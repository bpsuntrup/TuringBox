# TuringBox (WIP)
A turing machine emulator library.

# Building
Run `make`. This should output a library in bin/ called "libturing.a".

Running `make driver` will output a small driver executable that demonstrates
(mostly for the developer) the functionality of the library.

# Running Unit Tests
To compile the unit tests, run `make tests`. This outputs an executable
called `run_tests`. Have fun. If the word `FAIL` appears, they failed. Otherwise,
they passed.

Note that the many of the test files have a `.test` filename extension. This 
may have been a silly decision, but you can add something like
`au BufRead,BufNewFile *.test	setf cpp` to your .vimrc to get the C++ color
scheme you love.

# Version
0.0

# License
MIT (C) Benjamin Paul Suntrup. See COPYING.
