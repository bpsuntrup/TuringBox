#include "Case.h"
#include "Suite.h"
#include "Bed.h"
#include "Table.h"
#include "Test.h"

int main()
{
  Test::Bed testbed;

  // Test Table
  Test::Suite testTable;
  testTable.describe("Testing Table");
  testTable.addTest("Test Table::insertInstruction", []()
  {
    Table t;
    t.insertInstruction(1,2,3,4,'d');
    MachineAction m = t.getAction(1,2);
    // TODO: for some reason I get an undefined reference error when trying to
    //       use the assert method. That sucks. Fix it.
    //Test::assert(m.newState == 3, "see if state can be retrieved");
  });
  testbed.addSuite(&testTable); // TODO: use a reference instead

  // Run all tests
  testbed.runAllTests();
  return 0;
}
