#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include "Table.h"
#include "Tape.h"
// TODO: look up forward declaring and see if it applies

class TuringMachine 
{
  int state;
  int halt;
  Table table;

public:

  // insert 5-tuple Turing machine instruction, returning an instruction ID
  int insertInstruction(int state, int symbol, int newState, int newSymbol, 
                        char instruction);
  // void removeInstruction(int id);
  void run(Tape*);
  TuringMachine();
};

#endif
