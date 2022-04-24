#ifndef EXCEPTION
#define EXCEPTION

#include <iostream>
#include <exception>

class DuplicateChannelName : public std :: exception{
    const char* what();
};

class ChannelNotFound : public std :: exception{
    const char* what();
};

class SameChannelDest : public std :: exception{
    const char* what();
};

#endif
