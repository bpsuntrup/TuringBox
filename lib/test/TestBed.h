// TestBed.h
// 
// @author Benjamin Paul Suntrup
// @desc a thin encapsulation of a list of pointers to TestSuites
//
// In the future, this can have more functionality, like the ability to run a
// subset of tests. For now it just aggregates all of the tests into a single
// test bed, and runs them all at once.
//
#ifndef TESTBED_H
#define TESTBED_H

#include "TestSuite.h"
#include <list>



class TestBed
{
public:
  void addTestSuite(TestSuite*);
  void runAllTests();

private:
  static list<TestSuite*> suites_;
};
  
#endif
