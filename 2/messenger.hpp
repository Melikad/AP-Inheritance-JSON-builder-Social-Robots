#ifndef MESSENGER
#define MESSENGER

#include "bot.hpp"
#include "channel.hpp"
#include "exceptions.hpp"

#define addBotCommand "add_bot"
#define addChannelCommand "add_channel"
#define tellCommand "tell"

#define echoType "echo"
#define loggerType "logger"
#define fredType "fred"
#define librarianType "librarian"

class Messenger{
private:
    std :: vector<Channel*> channel;
public:
    Channel* findChannel(std :: string name);
    void addBot(std :: string botType);
    void addChannel(std :: string name);
    void tell(std :: string channelName, std :: string message);
    void run();
};

#endif
