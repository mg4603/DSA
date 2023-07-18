app: user.o main.o
	g++ user.o main.o -o app

user.o: user.cpp
	g++ -c user.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm app *.o