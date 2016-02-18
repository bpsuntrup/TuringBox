#include "Tape.h"

Tape::Tape(vector<int>){}
Tape::Tape() 
{
  this.tape = new vector<int>(TM_TAPE_WIDTH);
}

int Tape::getValue() { return this.tape[this.stylus]; }
void Tape::setValue(int symbol) { this.tape[this.stylus] = symbol; }

void Tape::moveStylusRight() {}
void Tape::moveStylusLeft() {}
int * Tape::getTape(int x, int y) {}

