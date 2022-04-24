#ifndef MYEXCEPTION
#define MYEXCEPTION

#include <iostream>
#include <exception>

class IdException : public std :: exception{
public:
    const char* what();
};

class KeyException : public std :: exception{
public:
    const char* what();
};

class TypeException : public std :: exception{
public:
    const char* what();
};

#endif
