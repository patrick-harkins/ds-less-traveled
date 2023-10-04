CFLAGS = -std=c99

all: test


DynamicArray: DynamicArray.c DynamicArray.h
	gcc $(CFLAGS) -c DynamicArray.c
test: DynamicArray
	gcc $(CFLAGS) -c DynamicArrayTest.c
	gcc $(CFLAGS) DynamicArrayTest.o DynamicArray.o -o DynamicArrayTest
gpt-test: DynamicArrayGpt.c
	gcc $(CFLAGS) -c DynamicArrayGpt.c
	gcc $(CFLAGS) DynamicArrayGpt.o DynamicArray.o -o DynamicArrayGpt
run-test: test gpt-test
	./DynamicArrayGpt
	./DynamicArrayTest
vg-test: test
	valgrind --leak-check=full --track-origins=yes ./DynamicArrayTest
	valgrind --leak-check=full --track-origins=yes ./DynamicArrayGpt

clean:
	rm -f *.o
	rm -f DynamicArrayTest
