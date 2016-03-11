// TestBed.h
// 
// @author Benjamin Paul Suntrup
// @desc a thin encapsulation of a list of pointers to TestSuites
//
// In the future, this can have more functionality, like the ability to run a
// subset of tests. For now it just aggregates all of the tests into a single
// test bed, and runs them all at once.
//
#ifndef BED_H
#define BED_H

#include "Suite.h"
#include <list>

namespace Test
{
  class Bed
  {
  public:
    void addSuite(Suite*);
    void runAllTests();

  private:
    static list<Suite*> suites_;
  };
}  
#endif
