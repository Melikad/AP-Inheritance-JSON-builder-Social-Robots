all: main.out

main.out: main.o messenger.o channel.o bot.o
	g++ -std=c++11 main.o messenger.o channel.o bot.o -o main.out

main.o: main.cpp messenger.hpp channel.hpp bot.hpp
	g++ -std=c++11 -c main.cpp

messenger.o: messenger.hpp messenger.cpp bot.hpp bot.cpp
	g++ -std=c++11 -c messenger.cpp

channel.o: channel.hpp channel.cpp bot.cpp bot.hpp
	g++ -std=c++11 -c channel.cpp

bot.o: bot.hpp bot.cpp
	g++ -std=c++11 -c bot.cpp

exceptions.o: exceptions.hpp exceptions.cpp
	g++ -std=c++11 -c exceptions.cpp

clean:
	rm *.o
	rm main.out
