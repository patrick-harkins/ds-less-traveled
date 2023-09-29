CFLAGS = -std=c99

all: test

LinkedList: LinkedList.c
	gcc $(CFLAGS) -c LinkedList.c
LinkedListTest: LinkedListTest.c
	gcc $(CFLAGS) -c LinkedListTest.c
Randomness: ../Randomness/Randomness.h ../Randomness/Randomness.c
	gcc $(CFLAGS) -c ../Randomness/Randomness.c -o ../Randomness/Randomness.o
test: LinkedListTest LinkedList Randomness
	gcc $(CFLAGS) LinkedListTest.o LinkedList.o ../Randomness/Randomness.o -o LinkedListTest
	
run-test: test
	./LinkedListTest
vg-test: test
	valgrind --leak-check=full --track-origins=yes ./LinkedListTest

clean:
	rm -f *.o
	rm -f LinkedListTest
