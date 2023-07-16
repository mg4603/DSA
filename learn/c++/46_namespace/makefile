math: math_utils.o main.o
	g++ math_utils.o main.o -o math

math_utils.o: math_utils.cpp
	g++ -c math_utils.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm *.o math