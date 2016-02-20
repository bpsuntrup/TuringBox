#ifndef TAPE_H
#define TAPE_H

#include <vector>
#include "constants.h"
using namespace std;

// This class is going to hold the symbols. It has simple get and set methods,
// as well as a "stylus" that will logically be the mounting point for the
// turing machine. Thus, when the machine is instructed to move left, it moves
// the stylus to the right, and vice versa.

class Tape 
{
  list<int> tape;
  int stylus;

public:
  Tape(vector<int>);
  Tape();
  
  // returns the value at the stylus
  int getValue();

  // Change the symbol at the stylus
  void setValue(int symbol);

  // Move stylus commands. These also must ensure that there is tape to the left
  // to move towards, and that the tape is initialized (with 0) as it moves to 
  // the right
  void moveStylusRight();
  void moveStylusLeft();

  // Get an array of symbols (ints) twixt (inclusive) x and y on the tape
  int * getTape(int x, int y);
};

#endif
