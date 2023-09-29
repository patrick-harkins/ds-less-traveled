CFLAGS = -std=c99

all: test


DoubleLinkedList: DoubleLinkedList.c DoubleLinkedList.h
	gcc $(CFLAGS) -c DoubleLinkedList.c
test: DoubleLinkedList
	gcc $(CFLAGS) -c DoubleLinkedListTest.c
	gcc $(CFLAGS) DoubleLinkedListTest.o DoubleLinkedList.o -o DoubleLinkedListTest
run-test: test
	./DoubleLinkedListTest
vg-test: test
	valgrind --leak-check=full --track-origins=yes ./DoubleLinkedListTest

clean:
	rm -f *.o
	rm -f DoubleLinkedListTest
