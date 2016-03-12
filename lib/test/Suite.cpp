#include "Suite.h"
#include <list>
#include <functional>
#include <iostream>
#include <string>


void Test::Suite::addTest(string description, function<void()> test)
{
  Test::Case c;
  c = test;
  c.describe(description);
  tests_.push_back(c);
}

void Test::Suite::addTest(function<void()> test)
{
  Test::Case c;
  c = test;
  tests_.push_back(c);
}

void Test::Suite::addTest(Test::Case testCase)
{
  tests_.push_back(testCase);
}

void Test::Suite::runTests()
{
  for (list<Case>::iterator it = tests_.begin();
       it != tests_.end();
       it++)
  {
    (*it)();
  }
}

bool Test::Suite::assert(bool expression, string description)
{
  if (!expression)
  {
    // TODO: Right now this will stop the program, but doesn't give very good
    //       clues as to what went wrong. At least pass back some sort of 
    //       stack trace.
    //
    // TODO: Make sure that a single failed test doesn't halt all the whole
    //       test bed. This might require a little elbow grease in the 
    //       runTests function after I've figured out the previous TO DO
    throw description;
  }
  return true;
}
