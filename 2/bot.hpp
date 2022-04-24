#ifndef BOT
#define BOT

#include <iostream>
#include <fstream>
#include <vector>
//#include "channel.hpp"

#define fredString "Hi"
#define fredReplaceString "Hello"
#define librarianString "Quiet!"
#define librarianMessagePeriod 5

class Channel;

class Bot{
private:
    Channel* src;
public:
    virtual void update(std :: string message) = 0;
    void setSrc(Channel* inputSrc);
    Channel* getSrc();
};

class Echo : public Bot{
private:
    Channel* dst;
public:
    Echo(Channel* inputSrc, Channel* inputDst);
    void update(std :: string message);
};

class Logger : public Bot{
private:
    std :: string filePath;
public:
    Logger(std :: string InputfilePath);
    void update(std :: string message);
};

class Fred : public Bot{
public:
    Fred(Channel* src);
    void update(std :: string message);
};

class Librarian : public Bot{
    int counter = 1;
public:
    Librarian(Channel* src);
    void update(std :: string message);
};

#endif
