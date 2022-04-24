#include "myException.hpp"


const char* IdException :: what(){
    return "Invalid id.";
}

const char* KeyException :: what(){
    return "Duplicate key.";
}

const char* TypeException :: what(){
    return "Undefined type.";
}
