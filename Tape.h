#ifndef TAPE_H
#define TAPE_H

#include <vector>

// This class is going to hold the symbols. It has simple get and set methods,
// as well as a "stylus" that will logically be the mounting point for the
// turing machine. Thus, when the machine is instructed to move left, it moves
// the stylus to the right, and vice versa.

class Tape 
{
  vector<int> tape (TM_TAPE_WIDTH);
  int stylus;

public:
  Tape(vector<int>);
  Tape();
  
  // returns the value at the stylus
  int getValue() { return this.tape[this.stylus]; }

  // Change the symbol at the stylus
  void setValue(int symbol) { this.tape[this.stylus] = symbol; }

  //
  int * getTape
};

#endif
