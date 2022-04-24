#include "exceptions.hpp"


const char* DuplicateChannelName :: what(){
    return "Channel already exists";
}

const char* ChannelNotFound :: what(){
    return "Channel does not exist";
}

const char* SameChannelDest :: what(){
    return "Source and destination cannot be the same channel";
}
