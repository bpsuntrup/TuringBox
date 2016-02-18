#include "Table.h"

//  int insertInstruction(int state, int symbol, int newState, int newSymbol, 
//                        char instruction);
//  void removeInstruction(int id);
//  machineAction_t getAction(int state, int symbol);

// TODO: implement Table methods


int Table::insertInstruction(int state, int symbol, int newState, int newSymbol, 
                             char instruction)
{
  machineState_t mStat;
  mStat.state = state;
  mStat.symbol = symbol;

  machineAction_t mAct;
  mAct.newState = newState;
  mAct.newSymbol = newSymbol;
  mAct.instruction = instruction;

  machineInstruction_t mInst;
  mInst.state = mStat;
  mInst.action = mAct;
  mInst.id = 0;  // TODO: figure out something to do with ID's or remove them

  this.table.push_back(mInst);
}
