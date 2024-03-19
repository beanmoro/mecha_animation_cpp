#include "Player.h"

Player::Player() :  counter(0), frTime(sf::seconds(0.075)), pauseAnimation(false),
                    gravity(0.0f), jump(false), onGround(false), trusterSpeed(0.f),
                    velocity(0), acceleration(0.4), friction(DEFAULT_FRICTION),
                    buttonPressed(false), maxGravity(15.0), isMoving(false), ground(320.f-64)
                    {

}
Player::~Player(){


}

void Player::init(){
    currentAnimation.setID(0);
    animWalking.setID(1);
    animStay.setID(2);
    animFlying.setID(3);

    animWalking.setTexture("Sprites/MECHA_WALKING.png");
    animStay.setTexture("Sprites/MECHA_STAY.png");
    animFlying.setTexture("Sprites/MECHA_FLYING.png");



    for(int i = 0; i < 8; i++){
        animWalking.addFrame(sf::IntRect(128*i, 0, 128, 128));
        //animStay.addFrame(sf::IntRect( (128*i)+128, 0, -128, 128));
        if(i < 6){
            //animFlying.addFrame(sf::IntRect( (128*i)+128, 0, -128, 128));
        }
    }



    //setAnimation(animWalking);
    sprite.setOrigin(128/2, 128/2);

}
void Player::update(sf::Time deltaTime){

    velocity += acceleration - (friction*velocity);

    //texture.loadFromFile("Sprites/MECHA_WALKING.png", animWalking.getFrame(counter));
    //sprite.setTexture(texture);
    setAnimation(animWalking, counter);



    //Calculo de tiempo
    cTime += deltaTime;
    if(cTime >= frTime){
        cTime = sf::microseconds(cTime.asMicroseconds() % frTime.asMicroseconds());
        if(!pauseAnimation){
            if(counter + 1 < currentAnimation.getSize()){
                counter++;
            }else{
                counter = 0;
            }
        }
    }

    //Teclado
    if(input(sf::Keyboard::A)){

        acceleration = -0.1;
        pauseAnimation = false;
        buttonPressed = true;
        sprite.setScale(-1,1);

    }else if(input(sf::Keyboard::D)){

        acceleration = 0.1;
        pauseAnimation = false;
        buttonPressed = true;
        sprite.setScale(1,1);

    }else{

        pauseAnimation = true;
        buttonPressed = false;
    }

    if(input(sf::Keyboard::W)){ jump = true;} else { jump = false;}

    if(jump){
        if(trusterSpeed < 10.f){
            trusterSpeed += 0.015f;
        }
        gravity = 0;
        position.y-=trusterSpeed;


    }else{
        if(trusterSpeed > 0.1){
            trusterSpeed -= 0.1;
        }

    }

    simpleDetections();
    updateGravity();
    updatePhysics();


    //Actualizar Posicion
    sprite.setPosition(position);

}


void Player::draw(sf::RenderWindow* win){

    win->draw(sprite);


}

bool Player::input(sf::Keyboard::Key k){

    return sf::Keyboard::isKeyPressed(k);

}

void Player::updateGravity(){

    if(position.y < ground){
        gravity += 0.10f;
    }else{
        position.y = ground;
        gravity = 0;
    }

    if(gravity > maxGravity){
        gravity = maxGravity;
    }

    position.y+=gravity;


}

void Player::updatePhysics(){

    if(!buttonPressed){
        if(velocity > 0.5){
            acceleration *= friction;
        }else if(velocity < -0.5){
            acceleration *= -friction;
        }
    }

    if(position.y < ground){
        onGround = false;
        pauseAnimation = true;
        friction = 0.004;

    }else{
        onGround = true;
        friction = DEFAULT_FRICTION;
    }

    position.x += velocity;

}

void Player::setAnimation(Animation anim, int _counter){
    //Cargar Frame escogido
    currentAnimation = anim;
    texture.loadFromFile( currentAnimation.getTexturePath() , currentAnimation.getFrame(_counter));
    sprite.setTexture(texture);
    AnimationID = currentAnimation.getID();


}

void Player::simpleDetections(){


    //Comprobar si el personaje se esta moviendo
    if(velocity > 0.5 || velocity < 0.5){
        isMoving = true;
    }else{
        isMoving = false;
    }

    //Crear terreno de testeo


    //Limitar maximo valor de la gravedad

    /*
    if(onGround && isMoving && AnimationID != animWalking.getID()){
        setAnimation(animWalking, counter);
    }else if( onGround && !isMoving && AnimationID != animStay.getID()){
        setAnimation(animStay, counter);
    }else if(AnimationID != animFlying.getID()){
        setAnimation(animFlying, counter);
    }*/

}
