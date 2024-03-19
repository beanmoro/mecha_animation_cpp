#include "Game.h"

Game::Game() :  _screenSize(640, 480),
                _gameState(PLAY)
{

}
Game::~Game(){

}

void Game::run(){
    createEvent();
    stepEvent();

}

void Game::createEvent(){


    _window.create(sf::VideoMode(_screenSize.x, _screenSize.y), "Juego 0");
    player1.init();


}

void Game::stepEvent(){

    while(_gameState != EXIT){
        frTime = gameTime.restart();
        inputEvent();
        player1.update(frTime);
        drawEvent();


    }

}

void Game::inputEvent(){
    sf::Event e;
    while(_window.pollEvent(e)){

        if(e.type == sf::Event::Closed){
            _gameState = EXIT;
            _window.close();
        }
    }
}

void Game::drawEvent(){

    //Limpiar Ventana

    _window.clear(sf::Color::Blue);
    player1.draw(&_window);
    //Pintar todas las texturas
    _window.display();
}
