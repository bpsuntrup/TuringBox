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

bool Test::Suite::runTests(ostream& o)
{
  // change this to false if any tests fail
  bool didItPass = true;
  for (list<Case>::iterator it = tests_.begin();
       it != tests_.end();
       it++)
  {
    // Below is a try/catch loop. If a test fails, it will throw a string.
    // Catch that string as "msg", and give some output to the user.
    // Print PASS to the ostream if it passes, and FAIL if it fails.
    try
    {
      o << it->describe() << ": ";
      (*it)();
    }
    catch (string msg)
    {
      o << "FAIL" << endl;
      o << "    Assert \"" << msg << "\" is false." << endl;
      didItPass = false;  // no it didn't
      continue;  // don't print PASS
    }
    
    o << "PASS" << endl;
  } // end for loop
  
  // Now print to the user whether the Suite as a whole passed or failed.
  o << description_ << ": " << (didItPass ? "PASS" : "FAIL") << endl;
}

void Test::Suite::describe(string description)
{
  description_ = description;
}

string Test::Suite::describe()
{
  return description_;
}
