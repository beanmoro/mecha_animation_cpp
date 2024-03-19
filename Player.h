#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#pragma once

#include "Essential_Include.h"
#include "Animation.h"

#define DEFAULT_FRICTION 0.08


class Player{

public:
    Player();
    ~Player();

    void init();
    void update(sf::Time deltaTime);

    void draw(sf::RenderWindow* win);


private:
    bool input(sf::Keyboard::Key k);
    void updateGravity();
    void updatePhysics();
    void simpleDetections();

    void setAnimation(Animation anim, int _counter);

    sf::Vector2f position;
    sf::Vector2i dimensions;

    Animation animWalking, animStay, animFlying;
    Animation currentAnimation;
    int AnimationID;

    sf::Texture texture;
    sf::Sprite sprite;
    int counter;


    sf::Time cTime;
    sf::Time frTime;

    float gravity;
    float trusterSpeed;

    bool pauseAnimation;
    bool onGround;
    bool jump;
    bool buttonPressed;
    bool isMoving;

    float ground;
    float velocity, acceleration, friction;

    float maxGravity;

};




#endif // PLAYER_H_INCLUDED
