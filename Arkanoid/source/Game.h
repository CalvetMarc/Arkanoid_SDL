#pragma once
#ifndef SDLPROJECT_GAME_H
#define SDLPROJECT_GAME_H
#include <vector>
#include "Map.h"
#include <SDL.h>
#include "Ball.h"
#include "GameState.h"
#include "CollisionsHelper.h"
#include "Pause.h"
#include "Audio.h"
#include "GameOver.h"

enum class Serve;
class Ball;
class Texture;
class Hero;
class InputHandler;
class map;

class Game : public GameState {
public:
    
    Game() = default;

    virtual void Start(GameStates& whichStates) override;

    virtual void HandleEvents(bool &keepPlaying, GameStates& whichStates) override;

    virtual bool Update(double elapsedSeconds) override;

    virtual void Render() override;

    virtual void End() override;

    bool musicPausedOnMenu = false;
    PlayingStates playingState;

private:
    void InitSDL();
    void CreateWindowAndRender();

    void InitLives();
    void InitBackground();
    void InitControllers();
    void InitPlayers();
    void InitBall();
    void InitMap();
    
    Pause* pauseMenu;
    bool pauseTransitionDone;

    GameOver* gameOver;
    bool gameOverTransitionDone;
    //bool gameOverMusicLoaded = false;

    PlayingStates currentState;

    SDL_Window* _window;
    SDL_Renderer* _renderer;
    std::vector<Texture*>livesP1;
    std::vector<Texture*>livesP2;
    SDL_Rect _livesRectP1;
    SDL_Rect _livesRectP2;
    Texture* _logoTexture;
    SDL_Rect _destLogoRect;
    
    SDL_Rect _destGameOverText;

    SDL_Point point;
    Serve gameServe;
    
    SDL_Texture* puntuationP1;
    Texture* PP1;
    Texture* PP2;    

    Hero* _hero;
    Hero* _hero2;
    Ball* _ball;
    Map* _map;    
    SDL_Rect _destPP1Rect;
    SDL_Rect _destPP2Rect;
    bool check1;
    bool check2;
    std::vector<SDL_Rect>spotsToCheckCollision;
    InputHandler* _inputHandler;
    int whoHitted;

    std::vector<Vector2D<float>>UpdateNormalBrickAnimation;

    /*void PopLiveAndPoints1();
    void PopLiveAndPoints2();*/
    void UpdateHUD();


};


#endif //SDLPROJECT_GAME_H


