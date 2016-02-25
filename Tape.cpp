#include "Tape.h"
#include "constants.h"

Tape::Tape() 
{
  this->tape.push_back(BLANK_SYMBOL);
  this->stylus = tape.begin();
}

Tape::Tape(int* symbols, int size, int position)
{
  for (int i = 0; i < size; i++)
  {
    this->tape.push_back(symbols[i]);
    if (i == position)
    {
      this->stylus = tape.end();
      (this->stylus)--;  // end() returns the "past the end" object in the list
    }
  }
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

