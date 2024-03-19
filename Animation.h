#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#pragma once

#include "Essential_Include.h"
#include <vector>


class Animation {

public:

    Animation();
    ~Animation();

    void addFrame(sf::IntRect rect);
    void setTexture(std::string path);

    sf::IntRect getFrame(unsigned int index);
    sf::Texture* getSpriteSheet();

    int getSize();
    std::string getTexturePath();

    void setID(int _id);
    int getID();

private:

    std::vector<sf::IntRect> frames;
    std::string Path;
    sf::Texture spriteSheet;
    int id;

};




#endif // ANIMATION_H_INCLUDED
