app: user.o main.o teacher.o
	g++ user.o main.o teacher.o -o app

teacher.o: teacher.cpp
	g++ -c teacher.cpp
	
user.o: user.cpp
	g++ -c user.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm app *.o