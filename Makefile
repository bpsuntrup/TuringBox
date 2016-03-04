TuringBox: main.o Tape.o TuringMachine.o Table.o
	g++ -o TuringBox main.o Tape.o TuringMachine.o Table.o
main.o:
	g++ -c main.cpp
Tape.o:
	g++ -c Tape.cpp
TuringMachine.o: 
	g++ -c TuringMachine.cpp
Table.o:
	g++ -c Table.cpp
clean:
	rm *.o
