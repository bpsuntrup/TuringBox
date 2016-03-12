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
#include <string>
#include "Case.h"
using namespace std;

// I think I could make this generic enough that I could pass a stream to the
// tests and have it print to whatever is passed to it... something to think
// about.

// I have a plan:
//  I need an assert function, and I need some way of identifying the asserts
//  and the test suites, so that when a failiure happens, I can know exactly 
//  where and what. I'll do this with descriptions.

namespace Test
{
  class Suite
  {
  public:
    void addTest(string description, function<void()> test);
    void addTest(function<void()> test);
    void addTest(Case testCase);
    void runTests();


    static bool assert(bool expression, string description = "");
  
  private:
    list<Case> tests_;
    string description_;
  };

} // end namespace Test
#endif
