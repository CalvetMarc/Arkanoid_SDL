

#include "Game.h"
#include "Exceptions/SDL_Exception.h"
#include "Engine/Graphics/Texture.h"
#include "Hero.h"
#include "Engine/Input/InputHandler.h"
#include "Engine/Input/Keyboard.h"
#include "Brick.h"
#include <vector>

int winnerPoints = 0;

const int UP = 1;
const int DOWN = 2;
//const int UPP2 = 3;
//const int DOWNP2 = 4;
//const int RIGHT = 2;
Keyboard* keyboard;
Keyboard* keyboard2;



void Game::Start(GameStates& whichStates) {


    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

//Definir els gamestates
    whichStates = GameStates::GAME;
    currentState = PlayingStates::STARTGAME;

    


    Audio::Instance()->LoadMusicGame();


    if (!Audio::Instance()->PausedMusic()) {
        Audio::Instance()->PlayMusic(-1);
    }
    if (Audio::Instance()->PausedMusic()) {
        musicPausedOnMenu = true;
    }
                    

    pauseTransitionDone = false;
    gameOverTransitionDone = false;
    //gameOver = false;

//Crear els jugadors 
    InitPlayers();
//Crear les vides   
    InitLives();
// Cargar fondo    
    InitBackground();
//Crear controls
    InitControllers();
//Crear la bola    
    InitBall();   
//Crear mapa   
    InitMap();

    //

   
}

void Game::InitSDL() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        throw SDL_Exception(SDL_GetError());
    }

}

void Game::CreateWindowAndRender() {
    SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &_window, &_renderer);

    if (_window == nullptr || _renderer == nullptr) {
        throw SDL_Exception(SDL_GetError());
    }
}

void Game::InitLives()
{
    livesP1.resize(3);
    livesP2.resize(3);

    _destPP1Rect.x = 75;
    _destPP1Rect.y = 495;


    _destPP2Rect.x = 460;
    _destPP2Rect.y = 495;


    //Omplir vidas  
    for (int i = 0; i < livesP1.size(); i++) {
        livesP1.at(i) = new Texture("resources/platform.png", _renderer, 0);
        livesP1.at(i)->Init();
    }

    for (int i = 0; i < livesP2.size(); i++) {
        livesP2.at(i) = new Texture("resources/platform.png", _renderer, 0);
        livesP2.at(i)->Init();
    }
   
}

void Game::InitBackground()
{
    _logoTexture = new Texture("resources/Backgroung.jpg", _renderer, 0);
    _logoTexture->Init();
    _destLogoRect.x = 0;
    _destLogoRect.y = 0;
    _destLogoRect.w = 800;
    _destLogoRect.h = 600;
}

void Game::InitControllers()
{
    _inputHandler = new InputHandler();
    keyboard = new Keyboard();
    keyboard2 = new Keyboard();
    auto button1 = InputButton{ UP, SDLK_w };
    auto button2 = InputButton{ DOWN, SDLK_s };
    auto button3 = InputButton{ UP, SDLK_UP };
    auto button4 = InputButton{ DOWN, SDLK_DOWN };
    keyboard->AddButtonMap(button1);
    keyboard->AddButtonMap(button2);
    keyboard2->AddButtonMap(button3);
    keyboard2->AddButtonMap(button4);
    _inputHandler->AddController(keyboard);
    _inputHandler->AddController(keyboard2);
}

void Game::InitPlayers()
{
    //Crear el jugador 1
    _hero = new Hero(_renderer, keyboard, 90, 10, 300, 80, 20, 0);
    _hero->Init();

    //Crear el jugador 1
    _hero2 = new Hero(_renderer, keyboard2, -90, 710, 300, 80, 20, 0);
    _hero2->Init();
}

void Game::InitBall()
{
    gameServe = Serve::P1;
    _ball = new Ball(_renderer, 0, 65, 100, 18, 18);    
    _ball->Init();
}

void Game::InitMap()
{
    _map = new Map(_renderer);
    _map->Init();
}


void Game::HandleEvents(bool &keepPlaying, GameStates& whichStates) {

//Comprovar inputs   
    
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.key.type == SDL_KEYDOWN)
        {
            switch (currentState) {
            case PlayingStates::STARTGAME:
                if (event.key.keysym.sym == SDLK_SPACE) {
                    gameServe = Serve::NO;
                    currentState = PlayingStates::RUNNING;
                }
                if (event.key.keysym.sym == SDLK_UP) {
                    _hero2->MoveUp();
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
                    _hero2->MoveDown();
                }
                if (event.key.keysym.sym == SDLK_w) {
                    _hero->MoveUp();
                }
                if (event.key.keysym.sym == SDLK_s) {
                    _hero->MoveDown();
                }
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    whichStates = GameStates::MENU;
                }
                break;
            case PlayingStates::RUNNING:

                if (event.key.keysym.sym == SDLK_UP) {
                    _hero2->MoveUp();
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
                    _hero2->MoveDown();
                }
                if (event.key.keysym.sym == SDLK_w) {
                    _hero->MoveUp();
                }
                if (event.key.keysym.sym == SDLK_s) {
                    _hero->MoveDown();
                }
                if (event.key.keysym.sym == SDLK_p) {
                    currentState = PlayingStates::PAUSED;
                }
                break;
            case PlayingStates::PAUSED:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    whichStates = GameStates::MENU;
                }
                if (event.key.keysym.sym == SDLK_SPACE) {
                    SDL_RenderClear(_renderer);
                    currentState = PlayingStates::RUNNING;
                }
                if (event.key.keysym.sym == SDLK_m) {
                    SDL_RenderClear(_renderer);
                    if (!Audio::Instance()->PausedMusic()) {
                        Audio::Instance()->PauseMusic();

                    }
                    else if (Audio::Instance()->PausedMusic()) {

                        if (musicPausedOnMenu) {
                            Audio::Instance()->LoadMusicGame();
                            Audio::Instance()->PlayMusic(-1);
                        }
                        else {
                            Audio::Instance()->ResumeMusic();
                        }
                    }
                }
                     
                break;
            case PlayingStates::GAMEOVER:
                if (event.key.keysym.sym == SDLK_SPACE) {
                    if (_hero->_points > _hero2->_points) {
                        winnerPoints = _hero->_points;

                    }
                    else {
                        winnerPoints = _hero2->_points;
                    }
                    whichStates = GameStates::RANKINGWRITE;
                    //winnerPoints = _hero2->_points;
                }

                
                break;
            default:
                break;

            }
            

        }
        if (event.key.type == SDL_KEYUP)
        {
            switch (currentState) {
            case PlayingStates::RUNNING:
                if (event.key.keysym.sym == SDLK_UP) {
                    _hero2->PutUpOff();
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
                    _hero2->PutDownOff();
                }
                if (event.key.keysym.sym == SDLK_w) {
                    _hero->PutUpOff();
                }
                if (event.key.keysym.sym == SDLK_s) {
                    _hero->PutDownOff();
                }
                break;
            case PlayingStates::STARTGAME:
                if (event.key.keysym.sym == SDLK_UP) {
                    _hero2->PutUpOff();
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
                    _hero2->PutDownOff();
                }
                if (event.key.keysym.sym == SDLK_w) {
                    _hero->PutUpOff();
                }
                if (event.key.keysym.sym == SDLK_s) {
                    _hero->PutDownOff();
                }
                break;
            case PlayingStates::PAUSED:
                break;
            case PlayingStates::GAMEOVER:
                break;
            }     
        }
        if (event.type == SDL_QUIT)
        {            
            keepPlaying = false;
        }
        else {
            keepPlaying = true;
        }
    }
}
    


bool Game::Update(double elapsedSeconds) {  
        
   
    if (currentState != PlayingStates::GAMEOVER && currentState != PlayingStates::PAUSED) {
        if (!Audio::Instance()->PausedMusic()) {
            Audio::Instance()->ResumeMusic();
        }
        pauseTransitionDone = false;
        // Update dels jugadors
        _hero2->Update(elapsedSeconds);
        _hero->Update(elapsedSeconds);
        // Update de la bola
        _ball->Update(elapsedSeconds, _hero, _hero2, _map, gameServe);
        // Update de vidas i punts
        UpdateHUD();
    }    
    if (currentState == PlayingStates::PAUSED) {
       
        //Audio::Instance()->PauseMusic();
        if (!pauseTransitionDone) {
            pauseMenu = new Pause(_renderer);
            //pauseMenu->Init();
            pauseTransitionDone = true;
        }
        pauseMenu->Update(elapsedSeconds);      
            
    }
    if (livesP1.empty() || livesP2.empty()) {
        currentState = PlayingStates::GAMEOVER;
    }
    if (currentState == PlayingStates::GAMEOVER) {
               
        
        if (!gameOverTransitionDone) {

            gameOver = new GameOver(_renderer);
                   
            Audio::Instance()->GameOverMusic();                   
            if (!Audio::Instance()->PausedMusic()) {
                Audio::Instance()->PlayMusic(0);
            }

            gameOverTransitionDone = true;
        }

        gameOver->Init();
        /*gameOver->Render();*/
    }    
    
    
    return true;
}

void Game::Render() {
    SDL_RenderClear(_renderer);

    // renderizar imagenes, etc.
    _logoTexture->Render(&_destLogoRect, 0);
    
    _destPP1Rect.w = PP1->widthPP * 4;
    _destPP1Rect.h = PP1->heigthPP * 4;
    _destPP2Rect.w = PP2->widthPP * 4;
    _destPP2Rect.h = PP2->heigthPP * 4;

    _livesRectP1.x = 75;
    _livesRectP1.y = 550; 
    _livesRectP1.w = 80;
    _livesRectP1.h = 20;

    _livesRectP2.x = 459;
    _livesRectP2.y = 550;
    _livesRectP2.w = 80;
    _livesRectP2.h = 20;


    PP1->Render(&_destPP1Rect, 0);
    PP2->Render(&_destPP2Rect, 0);

    _hero->Render();
    _hero2->Render();
    _ball->Render();
    _map->Render();

    for (int i = 0; i < livesP1.size(); i++) {
        livesP1.at(i)->Render(&_livesRectP1,0);
        _livesRectP1.x += 90;
    }

    for (int i = 0; i < livesP2.size(); i++) {
        livesP2.at(i)->Render(&_livesRectP2,0);
        _livesRectP2.x += 90;
    }
    
    if (currentState == PlayingStates::PAUSED) {
        pauseMenu->Render();
    }
    if (currentState == PlayingStates::GAMEOVER) {
        gameOver->Render();
    }
    
   
    SDL_RenderPresent(_renderer);    
    
}

void Game::End() {
    _hero->Release();
    _hero2->Release();
    _ball->Release();
    _logoTexture->Release();
    

    delete _hero;
    delete _hero2;
    delete _ball;
    delete _logoTexture;
    delete keyboard;
    delete keyboard2;
    delete _inputHandler;
    delete pauseMenu;

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    
}

void Game::UpdateHUD()
{
    if (_ball->Pop1) {
        currentState = PlayingStates::STARTGAME;
        gameServe = Serve::P1;
        livesP1.pop_back();
        if (_hero->_points >= 50) {
            _hero->_points -= 50;
        }
        else {
            _hero->_points = 0;
        }
        _hero2->_points += 100;
    }
    if (_ball->Pop2) {
        currentState = PlayingStates::STARTGAME;
        gameServe = Serve::P2;
        livesP2.pop_back();
        if (_hero2->_points >= 50) {
            _hero2->_points -= 50;
        }
        else {
            _hero2->_points = 0;
        }
        _hero->_points += 100;
    }

    PP1 = nullptr;
    PP2 = nullptr;

    PP1 = new Texture(_hero->_points, 1, _renderer, "PP");
    PP2 = new Texture(_hero2->_points, 2, _renderer, "PP2");
}
