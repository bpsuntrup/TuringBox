//
// @author Benjamin Paul Suntrup
// @license MIT (C) Benjamin Paul Suntrup
// @date 9 March 2016
//
// @class TestSuite
// @desc TestSuite is a class for defining test methods.
//

#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <functional>
#include <iostream> 
#include <list>
using namespace std;

// I think I could make this generic enough that I could pass a stream to the
// tests and have it print to whatever is passed to it... something to think
// about.


// Discussion: 
//   I will need to have an array of function objects which can then all be
//   called. I will need methods for adding function objects.
//


class TestSuite
{
public:
  void addTest(function<void()> test);
  void runTests();

  static bool assert(bool);
  
private:
  list<function<void()>> tests;
};

#endif
