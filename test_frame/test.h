#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Test runner class
class TestRunner {
 public:
  int passed = 0;
  int failed = 0;
  vector<pair<string, function<void()>>> tests;

  void addTest(const string& name, function<void()> testFunc) {
    tests.emplace_back(name, testFunc);
  }

  // ===== Generic Equality Comparison =====
  template <typename T>
  void assertEqual(const T& actual, const T& expected,
                   const string& name = "") {
    if (!(actual == expected)) {
      ostringstream ss;
      if (!name.empty()) ss << name << ": ";
      ss << "Expected: " << expected << ", Got: " << actual;
      throw ss.str();
    }
  }

  // ===== String comparison =====
  void assertEqual(const string& actual, const string& expected,
                   const string& name = "") {
    if (actual != expected) {
      ostringstream ss;
      if (!name.empty()) ss << name << ": ";
      ss << "Expected: \"" << expected << "\", Got: \"" << actual << "\"";
      throw ss.str();
    }
  }

  // ===== Vector<T> comparison (ordered) =====
  template <typename T>
  void assertEqual(const vector<T>& actual, const vector<T>& expected,
                   const string& name = "") {
    if (actual != expected) {
      ostringstream ss;
      if (!name.empty()) ss << name << ": ";
      ss << "Expected: " << formatVector(expected);
      ss << ", Got: " << formatVector(actual);
      throw ss.str();
    }
  }

  // ===== Vector<T> comparison (unordered - same content, any order) =====
  template <typename T>
  void assertSameContent(const vector<T>& actual, const vector<T>& expected,
                         const string& name = "") {
    if (actual.size() != expected.size()) {
      throw name + ": Size mismatch";
    }
    vector<T> sorted_actual = actual;
    vector<T> sorted_expected = expected;
    sort(sorted_actual.begin(), sorted_actual.end());
    sort(sorted_expected.begin(), sorted_expected.end());
    if (sorted_actual != sorted_expected) {
      ostringstream ss;
      if (!name.empty()) ss << name << ": ";
      ss << "Expected content: " << formatVector(sorted_expected);
      ss << ", Got: " << formatVector(actual);
      throw ss.str();
    }
  }

  // ===== Vector<vector<T>> comparison (ordered) =====
  template <typename T>
  void assertEqual(const vector<vector<T>>& actual,
                   const vector<vector<T>>& expected, const string& name = "") {
    if (actual != expected) {
      ostringstream ss;
      if (!name.empty()) ss << name << ": ";
      ss << "Expected: " << formatMatrix(expected);
      ss << ", Got: " << formatMatrix(actual);
      throw ss.str();
    }
  }

  // ===== Vector<vector<T>> comparison (unordered) =====
  template <typename T>
  void assertSameContent(const vector<vector<T>>& actual,
                         const vector<vector<T>>& expected,
                         const string& name = "") {
    if (actual.size() != expected.size()) {
      throw name + ": Size mismatch";
    }
    vector<vector<T>> sorted_actual = actual;
    vector<vector<T>> sorted_expected = expected;
    auto vecCmp = [](const vector<T>& a, const vector<T>& b) { return a < b; };
    sort(sorted_actual.begin(), sorted_actual.end(), vecCmp);
    sort(sorted_expected.begin(), sorted_expected.end(), vecCmp);
    if (sorted_actual != sorted_expected) {
      ostringstream ss;
      if (!name.empty()) ss << name << ": ";
      ss << "Expected content: " << formatMatrix(sorted_expected);
      ss << ", Got: " << formatMatrix(actual);
      throw ss.str();
    }
  }

  void assertTrue(bool condition, const string& msg) {
    if (!condition) {
      ostringstream ss;
      ss << "Expected true, Got: " << msg << " as False";
      throw ss.str();
    }
  }

  void assertFalse(bool condition, const string& msg) {
    if (condition) {
      ostringstream ss;
      ss << "Expected false, Got: " << msg << " as True";
      throw ss.str();
    }
  }

  void runAll() {
    cout << "Running " << tests.size() << " test(s)...\n\n";
    for (auto& [name, testFunc] : tests) {
      try {
        testFunc();
        cout << "[PASS] " << name << "\n";
        passed++;
      } catch (const string& err) {
        cout << "[FAIL] " << name << ": " << err << "\n";
        failed++;
      } catch (const char* err) {
        cout << "[FAIL] " << name << ": " << err << "\n";
        failed++;
      }
    }
    cout << "\n" << passed << " passed, " << failed << " failed\n";
  }

 private:
  template <typename T>
  string formatVector(const vector<T>& v) {
    ostringstream ss;
    ss << "[";
    for (size_t i = 0; i < v.size(); i++) {
      if (i > 0) ss << ", ";
      ss << v[i];
    }
    ss << "]";
    return ss.str();
  }

  template <typename T>
  string formatMatrix(const vector<vector<T>>& m) {
    ostringstream ss;
    ss << "[";
    for (size_t i = 0; i < m.size(); i++) {
      if (i > 0) ss << ", ";
      ss << "[";
      for (size_t j = 0; j < m[i].size(); j++) {
        if (j > 0) ss << ", ";
        ss << m[i][j];
      }
      ss << "]";
    }
    ss << "]";
    return ss.str();
  }
};

TestRunner test_runner;

// ===== Simple Test Macros =====
// Usage: test_runner.addTest("name", EXPECT_EQ(expr1, expr2))

#define EXPECT_EQ(actual, expected) \
  [=]() { test_runner.assertEqual(actual, expected); }

#define EXPECT_TRUE(condition) \
  [=]() { test_runner.assertTrue(condition, #condition); }

#define EXPECT_FALSE(condition) \
  [=]() { test_runner.assertFalse(condition, #condition); }

#define EXPECT_SAME(actual, expected) \
  [=]() { test_runner.assertSameContent(actual, expected); }
