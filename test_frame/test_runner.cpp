#include "test.h"

// Function to register tests - defined in user file
void registerTests();

int main() {
  registerTests();  // Call user-defined tests
  test_runner.runAll();
  return test_runner.failed > 0 ? 1 : 0;
}
