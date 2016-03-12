#include <string>
#include "Case.h"
using namespace std;

void Test::Case::operator() ()
{
  test_();
}

void Test::Case::operator= (function<void()> test)
{
  test_ = test;
}

void Test::Case::describe(string description)
{
  description_ = description;
}

string Test::Case::describe()
{
  return description_;
}
