#include "JsonBuilder.hpp"


void checkForException(Value* value, std :: string key = ""){
    if(value == NULL)
        throw IdException();
    if(value->getType() == ObjectType){
        std :: vector<Value*> values = value->getValue();
        for(int i = 0; i < values.size(); i++){
            if(values[i]->getKey() == key){
                throw KeyException();
                return;
            }
        }
    }
}


ContainerValue* JsonBuilder :: findContainer(int id, ContainerValue* container){
    if(container->getId() == id)
        return container;
    std::vector<Value*> values = container->getValue();
    for(int i = 0; i < values.size(); i++){
        if(values[i]->getType() == ObjectType || values[i]->getType() == ArrayType){
            ContainerValue* ContainerChild = dynamic_cast<ContainerValue*>(values[i]);
            ContainerValue* foundedValue = findContainer(id, ContainerChild);
            if(foundedValue != NULL)
                return foundedValue;
        }
    }
    return NULL;
}

void JsonBuilder :: addStringToContainer(int parentId, std::string key, std::string value){
    StringValue* stringValue = new StringValue(parentId, key, value);
    ContainerValue* object = findContainer(parentId, mainObject);
    checkForException(object);
    object->addValue(stringValue);
}

void JsonBuilder :: addIntegerToContainer(int parentId, std::string key, int value){
    IntValue* intValue = new IntValue(parentId, key, value);
    ContainerValue* object = findContainer(parentId, mainObject);
    checkForException(object);
    object->addValue(intValue);
}

int JsonBuilder :: addContainerToContainer(int parentId, std::string key, std::string type){
    if(type != ArrayType && type != ObjectType)
        throw TypeException();
    ContainerValue* containerValue = new ContainerValue(valuesCounter, key, type);
    ContainerValue* object = findContainer(parentId, mainObject);
    checkForException(object);
    object->addValue(containerValue);
    return valuesCounter++;
}

void JsonBuilder :: addStringToObject(int parentId, std::string key, std :: string value){
    addStringToContainer(parentId, key, value);
}

void JsonBuilder :: addIntegerToObject(int parentId, std::string key, int value){
    addIntegerToContainer(parentId, key, value);
}

int JsonBuilder :: addContainerToObject(int parentId, std::string key, std::string type){
    return addContainerToContainer(parentId, key, type);
}

void JsonBuilder :: addStringToArray(int parentId, std::string value){
    addStringToContainer(parentId, "", value);
}

void JsonBuilder :: addIntegerToArray(int parentId, int value){
    addIntegerToContainer(parentId, "", value);
}

int JsonBuilder :: addContainerToArray(int parentId, std::string type){
    return addContainerToContainer(parentId, "", type);
}

void JsonBuilder :: print(int id){
    ContainerValue* container = findContainer(id, mainObject);
    checkForException(container);
    std::string Json = container->getJsonFormat("");
    std::cout << Json.substr(0, Json.size()-2) << std::endl;
}
