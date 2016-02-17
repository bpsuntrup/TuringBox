#include "TuringMachine.h"

//  void insertInstruction();
//  void removeInstruction();
//  void run(Tape*);
//  TuringMachine();

int TuringMachine::insertInstruction(int state, int symbol, int newState,
                                     int newSymbol, char instruction)
{
  return this.table.insertInstruction(state, symbol, newState, newSymbol,
                                      instruction);
}
