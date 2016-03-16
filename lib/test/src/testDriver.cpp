//
// A brief test drive of the test suite itself...
//

#include "Suite.h"
#include "Bed.h"
#include "Case.h"
#include <iostream>
#include <functional>
using namespace std;


int main()
{
  // UX overall:
  cout << "Testing overall UX:" << endl;

  Test::Suite testBogus;

  testBogus.describe("Testing Bogus");

  testBogus.addTest("Test Bogus::firstMethod", []()
  {
    Test::Suite::assert(true, "This Should be true");
  });

  testBogus.addTest("Test Bogus::badlyImplementedMethod", []()
  {
    Test::Suite::assert(false, "see if false is true");
  });

  testBogus.addTest("Test Bogus::thirdMethod", []()
  {
    Test::Suite::assert(true, "You shouldn't see this");
  });

  testBogus.runTests();

  // Notes and TODO's: 
  //  - I don't like that the assert() function lives in Suite. Change that.
  //
  //  - I think maybe assert() should be overloaded to be able to take the
  //    description and the boolean in either order.
  //  
  //  - Test out what the UX would feel like for having multple Suites across
  //    multiple files.
}
