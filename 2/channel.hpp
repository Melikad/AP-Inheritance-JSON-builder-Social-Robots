#ifndef CHANNEL
#define CHANNEL

#include "bot.hpp"

class Channel{
private:
    std :: string name;
    std :: vector<Bot*> bot;
public:
    Channel(std :: string inputName);
    void broadcast(std :: string message);
    void addNewBot(Bot* newBot);
    std :: string getName();
};

#endif
