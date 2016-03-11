#include "Bed.h"
#include "Suite.h"
#include <list>
using namespace Test;

list<Suite*> Bed::suites_;

void Bed::addSuite(Suite *suite)
{
  suites_.push_back(suite); // This could possibly cause a bug?? observe
                            // closely
}

void Bed::runAllTests()
{
  for (list<Suite*>::iterator i = suites_.begin();
       i != suites_.end();
       i++)
  {
    (*i)->runTests();
  }
}
