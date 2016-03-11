#include "Suite.h"
#include "FailiureException.h"
#include <list>
#include <functional>
#include <iostream>

void Test::Suite::addTest(function<void()> test)
{
  tests.push_back(test);
}

void Test::Suite::runTests()
{
  for (list<function<void()>>::iterator it = tests.begin();
       it != tests.end();
       it++)
  {
    (*it)();
  }
}

bool Test::assert(bool expression)
{
  if (expression)
  {
    return expression;
  }
  else
  {
    // TODO: Right now this will stop the program, but doesn't give very good
    //       clues as to what went wrong. At least pass back some sort of 
    //       stack trace.
    //
    // TODO: Make sure that a single failed test doesn't halt all the whole
    //       test bed. This might require a little elbow grease in the 
    //       runTests function after I've figured out the previous TO DO
    FailiureException e;
    throw e;
  }
}
