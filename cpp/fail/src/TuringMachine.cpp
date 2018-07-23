#include "TuringMachine.h"
#include "Table.h"


TuringMachine::TuringMachine()
{
  this->table = new Table();
  this->halt = 0;  // halt should be false by default
}

int TuringMachine::insertInstruction(int state, int symbol, int newState,
                                     int newSymbol, char instruction)
{
  return this->table->insertInstruction(state, symbol, newState, newSymbol,
                                      instruction);
}

void TuringMachine::run(Tape* tape)
{
  // The main control loop
  while(!(this->halt))
  {
    // get the table instruction
    MachineAction action = this->table->getAction(this->state,
                                                  tape->getValue());

    // Order: Change the symbol on the tape first, then change state, then move
    //        or halt.
    tape->setValue(action.newSymbol);
    this->state = action.newState;

    switch (action.instruction)
    {
      case 'r':  // Move head right
        tape->moveStylusRight();
        break;
      case 'l':  // Move head left
        tape->moveStylusLeft();
        break;
      case 'h':  // halt the machine
        this->halt = 1;
        break;
      default:
        break;
        // TODO: Throw an error here. 
    }
  }
}
