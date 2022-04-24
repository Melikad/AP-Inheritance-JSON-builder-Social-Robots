#ifndef VALUE_HPP
#define VALUE_HPP "VALUE_HPP"

#define ContainerType "container"
#define ObjectType "object"
#define ArrayType "array"
#define IntType "int"
#define StringType "string"

#define TAB "    "

#define ObjectOpeningBracket "{"
#define ObjectClosingBracket "}"
#define ArrayOpeningBracket "["
#define ArrayClosingBracket "]"

#include <string>
#include <vector>
#include <iostream>

class Value{
private:
    int parentId;
    std :: string key;
    std :: string type;
public:
    virtual std :: string getJsonFormat(std :: string tab) = 0;
    void setParentId(int inputparentId);
    void setKey(std :: string inputKey);
    void setType(std :: string inputType);
    std :: string getType();
    std :: string getKey();
    virtual std :: vector<Value*> getValue() = 0;
    int getId();
    int getParentId();
};

class IntValue : public Value{
private:
    int value;
public:
    IntValue(int parentId, std :: string key, int inputValue);
    std :: string getJsonFormat(std :: string tab);
    std :: vector<Value*> getValue();
};

class StringValue : public Value{
private:
    std :: string value;
public:
    StringValue(int parentId, std :: string key, std :: string inputValue);
    std :: string getJsonFormat(std :: string tab);
    std :: vector<Value*> getValue();
};

class ContainerValue : public Value{
private:
    std::vector<Value*> values;
    int id;
public:
    ContainerValue(int id, std :: string key, std :: string inputType);
    void addValue(Value* value);
    std::vector<Value*> getValue();
    std :: string getJsonFormat(std :: string tab);
    int getId();
};

#endif
