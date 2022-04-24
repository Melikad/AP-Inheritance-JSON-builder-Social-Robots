all: main.out

main.out: main.o JsonBuilder.o value.o myException.o
	g++ -std=c++11 main.o JsonBuilder.o value.o -o main.out

main.o: main.cpp JsonBuilder.hpp value.hpp JsonBuilder.cpp myException.cpp value.cpp
	g++ -std=c++11 -c main.cpp

JsonBuilder.o: JsonBuilder.hpp JsonBuilder.cpp value.hpp value.cpp
	g++ -std=c++11 -c JsonBuilder.cpp

value.o: value.hpp value.cpp
	g++ -std=c++11 -c value.cpp

myException.o: myException.hpp myException.cpp
	g++ -std=c++11 -c myException.cpp

clean:
	rm *.o
	rm main.out
