#ifndef TABLE_H
#define TABLE_H

#include <list>

using namespace std;

struct machineState_t
{
  int state;
  int symbol;
};

struct machineAction_t
{
  int newState;
  int newSymbol;
  char instruction;
};

struct machineInstruction_t
{
  int id;
  machineState_t state;
  machineAction_t action;
};

class Table
{
  // TODO: change the 4
  list<machineInstruction_t> table;

public:
  // insert 5-tuple Turing machine instruction, returning an instruction ID
  int insertInstruction(int state, int symbol, int newState, int newSymbol, 
                        char instruction);
  // void removeInstruction(int id);
  machineAction_t getAction(int state, int symbol);
};

#endif
