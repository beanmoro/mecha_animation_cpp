#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#pragma once

#include "Essential_Include.h"
#include <SDL2/SDL.h>
#include "Animation.h"
#include "Player.h"

enum GameState { PLAY, EXIT};

class Game{
public:
    Game();
    ~Game();

    void run();

private:

    void createEvent();
    void stepEvent();
    void inputEvent();
    void drawEvent();

    sf::Vector2i _screenSize;

    sf::RenderWindow _window;

    Player player1;

    GameState _gameState;
    sf::Time frTime;
    sf::Clock gameTime;
};

#endif // GAME_H_INCLUDED
