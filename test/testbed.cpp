#include "Table.h"
#include "Test.h"

int main()
{
  Test::Bed testbed;

  #include "Table.test"

  // Run all tests
  testbed.runAllTests();
  return 0;
}
