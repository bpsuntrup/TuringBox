#include "Table.h"


int Table::insertInstruction(int state, int symbol, int newState, int newSymbol, 
                             char instruction)
{
  MachineStatus machineStatus;
  machineStatus.state = state;
  machineStatus.symbol = symbol;

  MachineAction machineAction;
  machineAction.newState = newState;
  machineAction.newSymbol = newSymbol;
  machineAction.instruction = instruction;

  MachineInstruction machineInstruction;
  machineInstruction.state = machineStatus;
  machineInstruction.action = machineAction;
  machineInstruction.id = 0;  // TODO: figure out something to do with ID's or remove them

  this->table.push_back(machineInstruction);

  return 0;  //TODO: Figure out something to do with id's
}

MachineAction Table::getAction(int state, int symbol)
{
  for (list<MachineInstruction>::iterator it=this->table.begin(); 
       it != this->table.end(); 
       ++it)
    {
      if ((*it).state.state == state && (*it).state.symbol ==symbol)
        return (*it).action;
    }
     
    // TODO: create custom exception, and declare in the function what kind
    //       of exception this method throws.
    throw "Sorry, bud; The table doesn't have an entry for that.";
}

Table Table::operator=(Table rhs)
{
  this->table = rhs.table;
  return (*this);
}
