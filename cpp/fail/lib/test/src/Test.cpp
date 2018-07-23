#include "Test.h"
#include <string>
using namespace std;


bool Test::assert(bool expression, string description)
{
  if (!expression)
  {
    throw description;
  }
  return true;
}
