#include "Tape.h"
#include "constants.h"
#include <iostream>
using namespace std;

Tape::Tape(int blankSymbol = 0) 
{
  this->tape.push_back(this->blankSymbol);
  this->stylus = tape.begin();
  this->blankSymbol = blankSymbol;
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
    this->tape.push_back(this->blankSymbol);
  (this->stylus)++;
}

void Tape::moveStylusLeft()
{
  if (this->stylus == this->tape.begin())
    this->tape.push_front(this->blankSymbol);
  (this->stylus)--;
}

// Returns a pointer to an array in the heap. Need to clearly document that the
// array needs to be "delete"ed to avoid memory leaks.... or figure out a
// different model.
int * Tape::getTape()
{
  int * array = new int[this->getTapeSize()];
  int j = 0;

  for (list<int>::iterator i = this->tape.begin();
       i != this->tape.end();
       i++)
  {
    cout << "j = " << j << endl;
    cout << "*i = " << *i << endl;
    array[j] = *i;
    j++;
  }

  return array;
}

