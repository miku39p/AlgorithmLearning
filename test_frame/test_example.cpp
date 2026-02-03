#include "basic.h"
#include "test.h"

/*
Example file demonstrating automated testing
*/

int calc(int x, int y) { return x + y; }

vector<int> getNums() { return {1, 2, 3}; }

vector<int> getNumsUnordered() { return {3, 1, 2}; }

vector<string> getStrings() { return {"hello", "world"}; }

vector<vector<int>> getMatrix() { return {{1, 2}, {3, 4}}; }

vector<vector<int>> getMatrixUnordered() { return {{3, 4}, {1, 2}}; }

bool getTrue() { return true; }

bool getFalse() { return false; }

void registerTests() {
  // Simple comparison - now simplified!
  test_runner.addTest("calc(3,5)=8", EXPECT_EQ(calc(3, 5), 8));
  test_runner.addTest("calc(-1,1)=0", EXPECT_EQ(calc(-1, 1), 0));
  test_runner.addTest("calc(0,0)=0", EXPECT_EQ(calc(0, 0), 0));

  // Vector comparison (ordered)
  test_runner.addTest("vector ordered",
                      EXPECT_EQ(getNums(), vector<int>({1, 3, 3})));

  // Vector comparison (unordered - same content, any order)
  test_runner.addTest("vector unordered",
                      EXPECT_SAME(getNumsUnordered(), vector<int>({1, 3, 2})));

  // String comparison
  test_runner.addTest("string comparison",
                      EXPECT_EQ(getStrings()[0], string("hello")));

  // Vector<vector> comparison (ordered)
  test_runner.addTest(
      "matrix ordered",
      EXPECT_EQ(getMatrix(), vector<vector<int>>({{1, 3}, {3, 4}})));

  // Vector<vector> comparison (unordered)
  test_runner.addTest(
      "matrix unordered",
      EXPECT_SAME(getMatrixUnordered(), vector<vector<int>>({{1, 2}, {3, 4}})));

  test_runner.addTest("test true", EXPECT_EQ(getTrue(), true));
}
