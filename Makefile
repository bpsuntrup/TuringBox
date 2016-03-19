objects = build/main.o build/Tape.o build/TuringMachine.o build/Table.o

bin/libturing.a: $(objects)
	ar cr bin/libturing.a $(objects)
driver: $(objects)
	g++ -o driver build/main.o build/Tape.o build/TuringMachine.o build/Table.o -I include
build/main.o:
	g++ -c src/main.cpp -o build/main.o -I include
build/Tape.o:
	g++ -c src/Tape.cpp -o build/Tape.o -I include
build/TuringMachine.o: 
	g++ -c src/TuringMachine.cpp -o build/TuringMachine.o -I include
build/Table.o:
	g++ -c src/Table.cpp -o build/Table.o -I include

# TODO: figure out how to easily include all of the dependencies for this
#       library:
lib/test/bin/libtest.a:
	cd lib/test
	make
	cd ../..

tests: test/testbed.cpp bin/libturing.a lib/test/bin/libtest.a
	g++ -std=c++11 -I include -I lib/test/include -L bin -L lib/test/bin -static test/testbed.cpp -lturing -ltest -o tests
	
clean:
	rm build/*.o
