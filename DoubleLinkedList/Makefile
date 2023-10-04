CFLAGS = -std=c99

all: test


DoubleLinkedList: DoubleLinkedList.c DoubleLinkedList.h
	gcc $(CFLAGS) -c DoubleLinkedList.c
test: DoubleLinkedList
	gcc $(CFLAGS) -c DoubleLinkedListTest.c
	gcc $(CFLAGS) DoubleLinkedListTest.o DoubleLinkedList.o -o DoubleLinkedListTest
gpt-test: DoubleLinkedListGpt.c
	gcc $(CFLAGS) -c DoubleLinkedListGpt.c
	gcc $(CFLAGS) DoubleLinkedListGpt.o DoubleLinkedList.o -o DoubleLinkedListGpt
run-test: test gpt-test
	./DoubleLinkedListGpt
	./DoubleLinkedListTest
vg-test: test
	valgrind --leak-check=full --track-origins=yes ./DoubleLinkedListTest
	valgrind --leak-check=full --track-origins=yes ./DoubleLinkedListGpt

clean:
	rm -f *.o
	rm -f DoubleLinkedListTest
