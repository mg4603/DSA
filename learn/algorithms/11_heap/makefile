executable: main.o max_heap.o
	g++ max_heap.o main.o -o executable

main.o: main.cpp
	g++ -c main.cpp

min_heap.o: min_heap.cpp
	g++ -c min_heap.cpp
	
max_heap.o: max_heap.cpp
	g++ -c max_heap.cpp

clean:
	rm *.o executable