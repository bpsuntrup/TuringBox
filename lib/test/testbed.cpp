//
// A brief test drive of the test suite itself...
//

#include "TestSuite.h"
#include <iostream>
#include <functional>
using namespace std;

void mary() { cout<< "mary"<<endl;}
void joe() {cout<<"joe"<<endl;}
void jack(){cout<<"jack"<<endl;}

int main()
{
  TestSuite t;
  function<void()> f;
  f = mary;
  t.addTest(f);
  f = joe;
  t.addTest(f);
  f = jack;
  t.addTest(f);
  t.runTests();
//  f();
}
