#include "test.h"

// Global test runner instance (the only definition)
TestRunner test_runner;

// Function to register tests - defined in user file
void registerTests();

#ifndef TEST_RUNNER_NO_MAIN
int main() {
  registerTests();  // Call user-defined tests
  test_runner.runAll();
  return test_runner.failed > 0 ? 1 : 0;
}
#endif
