#include "Tape.h"
#include "constants.h"

Tape::Tape() 
{
  this->tape.push_back(BLANK_SYMBOL);
  this->stylus = tape.begin();
}

int Tape::getValue() 
{
  return *(this->stylus);
}

void Tape::setValue(int symbol)
{
  *(this->stylus) = symbol;
}

void Tape::moveStylusRight()
{
  if (this->stylus == this->tape.end())
    this->tape.push_back(BLANK_SYMBOL);
  (this->stylus)++;
}

void Tape::moveStylusLeft()
{
  if (this->stylus == this->tape.begin())
    this->tape.push_front(BLANK_SYMBOL);
  (this->stylus)--;
}

int * Tape::getTape(int x, int y)
{}

