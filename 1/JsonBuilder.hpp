#ifndef JSONBUILDER
#define JSONBUILDER "JSONBUILDER"

#include <string>
#include "value.hpp"
#include <vector>
#include <iostream>
#include "myException.hpp"

class JsonBuilder{
private:
    ContainerValue* mainObject = new ContainerValue(0, "", ObjectType);
    int valuesCounter = 1;
public:
    ContainerValue* findContainer(int parentId, ContainerValue* container);
    void addStringToContainer(int parentId, std::string key, std::string value);
    void addIntegerToContainer(int parentId, std::string key, int value);
    int addContainerToContainer(int parentId, std::string key, std::string type);
    void addStringToObject(int parentId, std::string key, std::string value);
    void addIntegerToObject(int parentId, std::string key, int value);
    int addContainerToObject(int parentId, std::string key, std::string type);
    void addStringToArray(int parentId, std::string value);
    void addIntegerToArray(int parentId, int value);
    int addContainerToArray(int parentId, std::string type);
    void print(int id);
};

#endif
