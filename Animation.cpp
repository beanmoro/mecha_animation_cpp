#include "Animation.h"

Animation::Animation(): id(0){

}
Animation::~Animation(){

}

void Animation::addFrame(sf::IntRect rect){
    frames.push_back(rect);
}
void Animation::setTexture(std::string path){
    Path = path;
    spriteSheet.loadFromFile(path);
}
sf::IntRect Animation::getFrame(unsigned int index){

    return frames[index];
}

int Animation::getSize(){
    return (int) frames.size();
}

std::string Animation::getTexturePath(){
    return Path;
}

void Animation::setID(int _id){

    id = _id;
}

int Animation::getID(){
    return id;
}
