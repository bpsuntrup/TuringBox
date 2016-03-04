TuringBox: main.o Tape.o TuringMachine.o Table.o
	g++ -o TuringBox main.o Tape.o TuringMachine.o Table.o
main.o: main.cpp
	g++ -c main.cpp
Tape.o: Tape.cpp
	g++ -c Tape.cpp
TuringMachine.o: TuringMachine.cpp
	g++ -c TuringMachine.cpp
Table.o: Table.cpp
	g++ -c Table.cpp
