objects = main.o Tape.o TuringMachine.o Table.o
TuringBox: $(objects)
	g++ -o TuringBox build/main.o build/Tape.o build/TuringMachine.o build/Table.o -I include
main.o:
	g++ -c src/main.cpp -o build/main.o -I include
Tape.o:
	g++ -c src/Tape.cpp -o build/Tape.o -I include
TuringMachine.o: 
	g++ -c src/TuringMachine.cpp -o build/TuringMachine.o -I include
Table.o:
	g++ -c src/Table.cpp -o build/Table.o -I include
clean:
	rm build/*.o
