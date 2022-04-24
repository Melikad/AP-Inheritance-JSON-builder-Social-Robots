#include "bot.hpp"
#include "channel.hpp"

void Bot :: setSrc(Channel* inputSrc){
    src = inputSrc;
}

Channel* Bot :: getSrc(){
    return src;
}

Echo :: Echo(Channel* inputSrc, Channel* inputDst){
    this->setSrc(inputSrc);
    dst = inputDst;
}

void Echo :: update(std :: string message){
    dst->broadcast(message);
}

Logger :: Logger(std :: string InputfilePath){
    filePath = InputfilePath;
}

void Logger :: update(std :: string message){
    std :: ofstream outputFile;
    outputFile.open(filePath);
    outputFile << message << std :: endl;
    outputFile.close();
}

Fred :: Fred(Channel* src){
    this->setSrc(src);
}

void Fred :: update(std :: string message){
    if(message == fredString)
        this->getSrc()->broadcast(fredReplaceString);
}

Librarian :: Librarian(Channel* src){
    this->setSrc(src);
}

void Librarian :: update(std :: string message){
    if(counter%librarianMessagePeriod == 0){
        this->getSrc()->broadcast(librarianString);
        counter = 0;
    }
    counter++;
}
