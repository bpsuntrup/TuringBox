#include "TuringMachine.h"
#include "Table.h"

//  void insertInstruction();
//  void removeInstruction();
//  void run(Tape*);
//  TuringMachine();

TuringMachine::TuringMachine()
{
  // TODO: weird error
  // this->table = new Table();
  this->halt = 0;  // halt should be false by default
}

int TuringMachine::insertInstruction(int state, int symbol, int newState,
                                     int newSymbol, char instruction)
{
  return this->table.insertInstruction(state, symbol, newState, newSymbol,
                                      instruction);
}

void TuringMachine::run(Tape*)
{
}
