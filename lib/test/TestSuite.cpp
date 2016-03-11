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

bool TestSuite::assert(bool expression)
{
  if (expression)
  {
    return expression;
  }
  else /* TODO: throw an error and then */
  {
    return expression;
  }
}
