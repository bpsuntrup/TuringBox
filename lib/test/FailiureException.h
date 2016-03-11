#ifndef FAILIUREEXCEPTION_H
#define FAILIUREEXCEPTION_H

#include <exception>
using namespace std;

namespace Test
{

  class FailiureException: public exception
  {
    virtual const char* what() const throw()
    {
      return "Test failed.";
    }
  };

}

#endif
