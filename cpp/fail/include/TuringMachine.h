// TODO: learn how doxygen works and make these comments work with doxygen
/** Title:       TuringMachine.h
 *  Author:      Benjamin Paul Suntrup
 *  License:     MIT (C) 2016
 *               // TODO: figure out what to write exactly for "license"
 *
 *  Brief:       a turing machine emulator.
 *
 *  Description: This header file contains the TuringMachine class, the main
 *               emulator. You'll notice that in this implementation, a Turing
 *               machine doesn't contain a tape, but is passed a tape. This
 *               seemed appropriate to me since a tape can be thought of as a
 *               program, wherefore a person might find it useful to run a 
 *               pre-programmed machine on several different tapes.
 */

#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include "Table.h"
#include "Tape.h"
// TODO: look up forward declaring and see if it applies

/** Class:       TuringMachine
 *  Brief:       a turing machine emulator.
 *  Details:     As described above, this class provides all of the main
 *               functionality required to emulate a Turing machine, including
 *               programming methods and a run() method.
 */
class TuringMachine 
{
  int state;
  int halt;
  Table *table;

public:

  /** insertInstruction(int, int, int, int, char)
   *
   *  Insert a 5-tuple Turing machine instruction, returning an instruction ID.
   *  For more information, please research Turing machines. Hopefully it will
   *  make more sense.
   *
   *  @pre
   *     The "instruction" parameter must be within the specified range
   *     (currently 'r', 'l', or 'h').
   *  @post
   *      A 5-tuple instruction will be added to the TuringMachine's Table, 
   *      including the current state of the machine, the symbol on the tape,
   *      the state the machine should change to, the symbol the machine should
   *      write to the tape, and then whether to move right, left, or halt.
   *  @param state
   *      represents the "current" state of the machine in the 5-tuple
   *  @param symbol
   *      represents the symbol on the tape in the 5-tuple
   *  @param newState
   *      represents the state the machine should change if the machine's state
   *      is equal to the state parameter and the tape's current symbol is
   *      equal to the symbol parameter
   *  @param newSymbol
   *      represents the symbol that should be printed to the tape if the 
   *      machine's state is equal to the state parameter and the tape's current
   *      symbol is equal to the symbol parameter
   *  @param 'r','l','h' instruction
   *      represents the action that the TuringMachine should take if this
   *      instruction is triggered; 'r' means the turing machine should "move 
   *      right", 'l' means the turing machine should "move left", and 'h' means
   *      the turing machine should halt.
   *  @return
   *      returns the instruction ID of the inserted instruction. Right now this
   *      is not used. It is intended to have some sort of functionality in the
   *      future. Can effectively be ignored for now...
   */
  int insertInstruction(int state, int symbol, int newState, int newSymbol, 
                        char instruction);
  int setState(int state) { this->state = state; }

  // void removeInstruction(int id);
  void run(Tape*);
  TuringMachine();
};

#endif
