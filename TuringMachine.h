#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include "Table.h"
#include "Tape.h"

class TuringMachine 
{
  int state;
  int halt;
  Table table;

public:
  void insertInstruction();
  void removeInstruction();
  void run(Tape*);
  TuringMachine();
};

#endif
