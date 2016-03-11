#include "Suite.h"
#include <list>
#include <functional>
#include <iostream>
using namespace Test;

void Suite::addTest(function<void()> test)
{
  tests.push_back(test);
}

void Suite::runTests()
{
  for (list<function<void()>>::iterator it = tests.begin();
       it != tests.end();
       it++)
  {
    (*it)();
  }
}

bool assert(bool expression)
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
