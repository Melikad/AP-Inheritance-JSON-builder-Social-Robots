#include "value.hpp"

int Value :: getId(){
    return -1;
}

int Value :: getParentId(){
    return parentId;
}

void Value :: setParentId(int inputId){
    parentId = inputId;
}

void Value :: setKey(std :: string inputKey){
    key = inputKey;
}

void Value :: setType(std :: string inputType){
    type = inputType;
}

std :: string Value :: getType(){
    return type;
}

std :: string Value :: getKey(){
    return key;
}

IntValue :: IntValue(int parentId, std :: string key, int inputValue){
    value = inputValue;
    this->setParentId(parentId);
    this->setKey(key);
}

std :: string IntValue :: getJsonFormat(std :: string tab){
    std :: string Json = tab;
    if(this->getKey() != "")
        Json += "\"" + this->getKey() + "\": ";
    Json += std :: to_string(value);
    Json += ",\n";
    return Json;
}

std :: vector<Value*> IntValue :: getValue(){

}


StringValue :: StringValue(int parentId, std :: string key, std :: string inputValue){
    value = inputValue;
    this->setParentId(parentId);
    this->setKey(key);
}

std :: string StringValue :: getJsonFormat(std :: string tab){
    std :: string Json = tab;
    if(this->getKey() != ""){
        Json += "\"" + this->getKey() + "\": ";
    }
    Json += "\"" + value + "\"";
    Json += ",\n";
    return Json;
}

std :: vector<Value*> StringValue :: getValue(){

}


ContainerValue :: ContainerValue(int inputId, std :: string key, std :: string inputType){
    id = inputId;
    this->setKey(key);
    this->setType(inputType);
}

void ContainerValue :: addValue(Value* value){
    values.push_back(value);
}

std::vector<Value*> ContainerValue :: getValue(){
    return values;
}

int ContainerValue :: getId(){
    return id;
}

std :: string ContainerValue :: getJsonFormat(std :: string tab){
    std :: string JsonFormat = tab;
    if(this->getId() != 0){
        JsonFormat += "\"";
        JsonFormat += this->getKey();
        JsonFormat += "\": ";
    }
    JsonFormat += (this->getType() == "object"? ObjectOpeningBracket: ArrayOpeningBracket);
    if(values.size() == 0){
        JsonFormat += (this->getType() == "object"? ObjectClosingBracket: ArrayClosingBracket);
        JsonFormat += ",\n";
        return JsonFormat;
    }
    JsonFormat += "\n";
    std::vector<Value*> values = this->getValue();
    for(int i = 0; i < values.size(); i++){
        std :: string newJsonValue = values[i]->getJsonFormat(tab+TAB);
        if(i+1 == values.size()){
            newJsonValue = newJsonValue.substr(0, newJsonValue.size()-2);
            newJsonValue += "\n";
        }
        JsonFormat += newJsonValue;
    }
    JsonFormat += tab;
    JsonFormat += (this->getType() == "object"? ObjectClosingBracket: ArrayClosingBracket);
    JsonFormat += ",";
    JsonFormat += "\n";
    return JsonFormat;
}
