#ifndef TABLE_H
#define TABLE_H

#include <list>

using namespace std;

struct MachineStatus
{
  int state;
  int symbol;
};

struct MachineAction
{
  int newState;
  int newSymbol;
  char instruction;
};

struct MachineInstruction
{
  int id;
  MachineStatus state;
  MachineAction action;
};

class Table
{
  // TODO: change the 4
  list<MachineInstruction> table;

public:
  // insert 5-tuple Turing machine instruction, returning an instruction ID
  int insertInstruction(int state, int symbol, int newState, int newSymbol, 
                        char instruction);
  // void removeInstruction(int id);
  MachineAction getAction(int state, int symbol);
  Table operator=(Table rhs);
};

#endif
