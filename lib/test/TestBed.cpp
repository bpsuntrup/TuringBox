#include "TestBed.h"
#include "TestSuite.h"
#include <list>

list<TestSuite*> TestBed::suites_;

void TestBed::addTestSuite(TestSuite *testSuite)
{
  suites_.push_back(testSuite); // This could possibly cause a bug?? observe
                                // closely
}

void TestBed::runAllTests()
{
  for (list<TestSuite*>::iterator i = suites_.begin();
       i != suites_.end();
       i++)
  {
    (*i)->runTests();
  }
}
