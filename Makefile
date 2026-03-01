CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = main
MAKEFLAGS += -k

.PHONY: all clean run

all: $(TARGET)

$(TARGET): main.o Heap-Objects/Dynamic-Array/dynamic_array.o Heap-Objects/Primitive-Objects/object.o Heap-Objects/Stack/stack.o Virtual-Machine/vm.o refcounter.o marknsweep.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c Heap-Objects/Dynamic-Array/dynamic_array.h Heap-Objects/Primitive-Objects/object.h Heap-Objects/Stack/stack.h Virtual-Machine/vm.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

Virtual-Machine/vm.o: Virtual-Machine/vm.c Virtual-Machine/vm.h Heap-Objects/Stack/stack.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

Heap-Objects/Stack/stack.o: Heap-Objects/Stack/stack.c Heap-Objects/Stack/stack.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

Heap-Objects/Dynamic-Array/dynamic_array.o: Heap-Objects/Dynamic-Array/dynamic_array.c Heap-Objects/Dynamic-Array/dynamic_array.h Heap-Objects/Primitive-Objects/object.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

Heap-Objects/Primitive-Objects/object.o: Heap-Objects/Primitive-Objects/object.c Heap-Objects/Primitive-Objects/object.h Heap-Objects/Dynamic-Array/dynamic_array.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

refcounter.o:
	$(CC) $(CFLAGS) -I. -c "Garbage-Collector/Reference-Counting/ref_counter.c" -o $@

marknsweep.o: Garbage-Collector/Mark-and-Sweep/mark-and-sweep.c Garbage-Collector/Mark-and-Sweep/ms.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

run: $(TARGET)
	./$(TARGET)
	rm -f Virtual-Machine/vm.o marknsweep.o

clean:
	rm -f *.o Heap-Objects/*/*.o "Garbage-Collector"/*/*.o $(TARGET)
