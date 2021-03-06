#ifndef TAPE_H
#define TAPE_H

#include <list>
#include "constants.h"
using namespace std;

// This class is going to hold the symbols. It has simple get and set methods,
// as well as a "stylus" that will logically be the mounting point for the
// turing machine. Thus, when the machine is instructed to move left, it moves
// the stylus to the right, and vice versa.

class Tape 
{
  list<int> tape;
  list<int>::iterator stylus;
  int blankSymbol;

public:
  Tape(int);

  // takes an array of integers, the size of the array, and a desired beginning
  // position for the stylus, and creates an initialized tape.
  //
  // pre: "symbols" is a pointer to an array of integers. "size" is the number
  //      of elements in the array, and "position" is a valid array index 
  //      (twixt 0 and size-1 inclusive). "size" must be at least 1, and may not
  //      be negative.
  //
  // post: The tape will be initialized with the values in the array with the
  //       stylus pointing to the value specified by the "position" index.
  Tape(int* symbols, int size, int position=0);
  
  // returns the value at the stylus
  int getValue();

  // Change the symbol at the stylus
  void setValue(int symbol);

  // Move stylus commands. These also must ensure that there is tape to the left
  // to move towards, and that the tape is initialized (with 0) as it moves to 
  // the right
  void moveStylusRight();
  void moveStylusLeft();

  // Returns an array of integers corresponding to the tape 
  int * getTape();

  // Return current size of tape list
  int getTapeSize() { return tape.size(); }
};

#endif
