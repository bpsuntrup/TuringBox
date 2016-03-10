#include "TestSuite.h"
#include <list>
#include <functional>
#include <iostream>

void TestSuite::addTest(function<void()> test)
{
  tests.push_back(test);
}

void TestSuite::runTests()
{
  for (list<function<void()>>::iterator it = tests.begin();
       it != tests.end();
       it++)
  {
    (*it)();
  }
}
