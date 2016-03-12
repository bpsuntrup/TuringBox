#ifndef CASE_H
#define CASE_H

#include <string>
#include <functional>
using namespace std;


namespace Test
{

  class Case
  {
  public:
    // TODO: consider making the = operator return something. For right now it
    //       probably doesn't matter.
    // TODO: if there are problems, I might need to write a copy constructor
    //       and all that "rule of three" jazz.
    void operator= (function<void()>);
    void operator() ();
    
    void describe(string description);
    string describe();

  private:
    function<void()> test_;
    string description_;
  };
}

#endif
