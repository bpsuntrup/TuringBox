#ifndef TEST_H
#define TEST_H

#include "Case.h"
#include "Suite.h"
#include "Bed.h"
#include <string>
using namespace std;

namespace Test
{
  bool assert(bool expression, string description = "");
}

#endif
