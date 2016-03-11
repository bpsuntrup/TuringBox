//
// A brief test drive of the test suite itself...
//

#include "Suite.h"
#include "Bed.h"
#include <iostream>
#include <functional>
using namespace std;

void mary() { cout<< "mary"<<endl;}
void joe() {cout<<"joe"<<endl;}
void jack(){cout<<"jack"<<endl;}

int main()
{
  Test::Suite t;
  function<void()> f;
  f = mary;
  t.addTest(f);
  f = joe;
  t.addTest(f);
  f = jack;
  t.addTest(f);
  t.addTest([](){ cout << "Anonymous" << endl; });
  t.runTests();
//  f();

  Test::Bed b;
  b.addSuite(&t);

  cout <<"Running TestBed tests:" << endl;
  b.runAllTests();
}
