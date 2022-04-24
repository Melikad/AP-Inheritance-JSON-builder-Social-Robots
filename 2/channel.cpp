#include "channel.hpp"

Channel :: Channel(std :: string inputName){
    name = inputName;
}

void Channel :: broadcast(std :: string message){
    for(int i = 0; i < bot.size(); i++){
        bot[i]->update(message);
    }
}

void Channel :: addNewBot(Bot* newBot){
    bot.push_back(newBot);
}

std :: string Channel :: getName(){
    return name;
}
