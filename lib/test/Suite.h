//
// @author Benjamin Paul Suntrup
// @license MIT (C) Benjamin Paul Suntrup
// @date 9 March 2016
//
// @class TestSuite
// @desc TestSuite is a class for defining test methods.
//

#ifndef SUITE_H
#define SUITE_H

#include <functional>
#include <iostream> 
#include <list>
using namespace std;

// I think I could make this generic enough that I could pass a stream to the
// tests and have it print to whatever is passed to it... something to think
// about.


namespace Test
{
  // basic assert for testing:
  bool assert (bool);

  class Suite
  {
  public:
    void addTest(function<void()> test);
    void runTests();

    static bool assert(bool);
  
  private:
    list<function<void()>> tests;
  };

} // end namespace Test
#endif
