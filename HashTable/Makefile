CFLAGS = -std=c99

all: test


HashTable: HashTable.c HashTable.h
	gcc $(CFLAGS) -c HashTable.c
test: HashTable
	gcc $(CFLAGS) -c HashTableTest.c
	gcc $(CFLAGS) HashTableTest.o HashTable.o -o HashTableTest
run-test: test
	./HashTableTest
vg-test: test
	valgrind --leak-check=full --track-origins=yes ./HashTableTest

clean:
	rm -f *.o
	rm -f HashTableTest
