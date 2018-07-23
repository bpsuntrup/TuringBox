objects = build/Suite.o build/Case.o build/Bed.o build/Test.o
CC = g++ -std=c++11

bin/libtest.a: $(objects)
	ar cr bin/libtest.a $(objects)

build/Case.o: include/Case.h src/Case.cpp
	$(CC) -c -o build/Case.o src/Case.cpp -I include

build/Suite.o: include/Suite.h include/Case.h src/Suite.cpp
	$(CC) -c -o build/Suite.o src/Suite.cpp -I include

build/Bed.o: include/Bed.h include/Suite.h include/Case.h src/Bed.cpp
	$(CC) -c -o build/Bed.o src/Bed.cpp -I include

build/Test.o: src/Test.cpp include/Test.h
	$(CC) -c -o build/Test.o src/Test.cpp -I include

driver: bin/libtest.a 
	$(CC) src/testDriver.cpp bin/libtest.a -o Driver -I include

.PHONY: clean
clean:
	-rm -f bin/libtest.a driver $(objects)
