#include "messenger.hpp"

Channel* Messenger :: findChannel(std :: string name){
    for(int i = 0; i < channel.size(); i++)
        if(channel[i]->getName() == name)
            return channel[i];
    throw ChannelNotFound();
}

void Messenger :: addBot(std :: string botType){
    if(botType == echoType){
        std :: string srcChannelName, dstChannelName;
        std :: cin >> srcChannelName >> dstChannelName;
        Channel* srcChannel = findChannel(srcChannelName);
        Channel* dstChannel = findChannel(dstChannelName);
        if(srcChannel->getName() == dstChannel->getName())
            throw SameChannelDest();
        Bot* echo = new Echo(srcChannel, dstChannel);
        srcChannel->addNewBot(echo);
    }
    if(botType == loggerType){
        std :: string fileName;
        std :: cin >> fileName;
        Bot* logger = new Logger(fileName);
        for(int i = 0; i < channel.size(); i++)
            channel[i]->addNewBot(logger);
    }
    if(botType == fredType){
        std :: string srcChannelName;
        std :: cin >> srcChannelName;
        Channel* channel = findChannel(srcChannelName);
        Bot* fred = new Fred(channel);
        channel->addNewBot(fred);
    }
    if(botType == librarianType){
        std :: string srcChannelName;
        std :: cin >> srcChannelName;
        Channel* channel = findChannel(srcChannelName);
        Bot* librarian = new Librarian(channel);
        channel->addNewBot(librarian);
    }
}

void Messenger :: addChannel(std :: string name){
    for(int i = 0; i < channel.size(); i++){
        if(channel[i]->getName() == name)
            throw DuplicateChannelName();
    }
    Channel* newChannel = new Channel(name);
    channel.push_back(newChannel);
}

void Messenger :: tell(std :: string channelName, std :: string message){
    Channel* channel = findChannel(channelName);
    channel->broadcast(message);
}

void Messenger :: run(){
    while(1){
        std :: string command;
        std :: cin >> command;
        std :: string channelName;
        std :: string botType;
        std :: string message;
        if(command == addBotCommand){
            std :: cin >> botType;
            addBot(botType);
        }
        if(command == addChannelCommand){
            std :: cin >> channelName;
            addChannel(channelName);
        }
        if(command == tellCommand){
            std :: cin >> channelName >> message;
            tell(channelName, message);
        }
    }
}
