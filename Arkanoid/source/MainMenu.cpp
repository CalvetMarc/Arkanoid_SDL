#include "MainMenu.h"
#include "Exceptions/SDL_Exception.h"

#include <iostream>


//MainMenu::MainMenu()
//{
//    //Init();
//}

void MainMenu::Start(GameStates& whichStates)
{
    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

    stateSelect = 1;

    //_inputHandler = new InputHandler();
    //Audio::Instance(0)->LoadMusicMenu();
    Audio::Instance()->LoadMusicMenu();
    if (!Audio::Instance()->musicPaused) {
        Audio::Instance()->PlayMusic(-1);
    }

    //_inputHandler = new InputHandler();    

    ArrowText = new Texture("resources/Arrow.png", _renderer, 0);
    ArrowText->Init();
    _destArrowTextRect.x = 250;
    _destArrowTextRect.y = 121;
    _destArrowTextRect.w = 75;
    _destArrowTextRect.h = 25;


    PlayText = new Texture(0, 0, _renderer, "PlayText");
    RankText = new Texture(0, 0, _renderer, "RankText");
    AudioText = new Texture(0, 0, _renderer, "AudioText");
    ExitText = new Texture(0, 0, _renderer, "ExitText");


    _isRunning = true;
}

void MainMenu::HandleEvents(bool& keepPlaying, GameStates& whichStates)
{
    //_inputHandler->PreHandleEvent();
    SDL_Event event;


    while (SDL_PollEvent(&event)) {

        if (event.key.type == SDL_KEYDOWN)
        {            
            if (event.key.keysym.sym == SDLK_DOWN) {
                switch (stateSelect)
                {
                case 1:
                    stateSelect = 2;
                    _destArrowTextRect.x = 213;
                    _destArrowTextRect.y = 223;
                    break;
                case 2:
                    stateSelect = 3;
                    _destArrowTextRect.x = 240;
                    _destArrowTextRect.y = 324;
                    break;
                case 3:
                    stateSelect = 4;
                    _destArrowTextRect.x = 255;
                    _destArrowTextRect.y = 420;
                    break;
                case 4:
                    stateSelect = 1;
                    _destArrowTextRect.x = 250;
                    _destArrowTextRect.y = 121;
                    break;
                default:
                    break;
                }
            }
            if (event.key.keysym.sym == SDLK_UP) {
                switch (stateSelect)
                {
                case 1:
                    stateSelect = 4;
                    _destArrowTextRect.x = 255;
                    _destArrowTextRect.y = 420;
                    
                    break;
                case 2:
                    stateSelect = 1;
                    _destArrowTextRect.x = 250;
                    _destArrowTextRect.y = 121;
                    
                    break;
                case 3:
                    stateSelect = 2;
                    _destArrowTextRect.x = 213;
                    _destArrowTextRect.y = 223;
                                       
                    break;
                case 4:
                    stateSelect = 3;
                    _destArrowTextRect.x = 240;
                    _destArrowTextRect.y = 324;        
                    break;
                default:
                    break;
                }
            }            
            if (stateSelect == 1 && event.key.keysym.sym == SDLK_RETURN) {
                //gameState = GameState::Game;

                whichStates = GameStates::GAME;
            }
            else if (stateSelect == 2 && event.key.keysym.sym == SDLK_RETURN) {
                whichStates = GameStates::RANKINGREAD;
 
            }
            else if (stateSelect == 3 && event.key.keysym.sym == SDLK_RETURN) {

                if (!Audio::Instance()->PausedMusic()) {
                    Audio::Instance()->PauseMusic();

                }
                else if (Audio::Instance()->PausedMusic()) {
                    Audio::Instance()->LoadMusicMenu();
                    Audio::Instance()->PlayMusic(-1);

                }
                
            }
            else if (stateSelect == 4 && event.key.keysym.sym == SDLK_RETURN) {


                exit(0);
            }

        }
        if (event.type == SDL_QUIT)
        {
            keepPlaying = false;
        }
    }
}

bool MainMenu::Update(double elapsedSeconds)
{

    PlayText = new Texture(0, 0, _renderer, "PlayText");
    RankText = new Texture(0, 0, _renderer, "RankText");
    AudioText = new Texture(0, 0, _renderer, "AudioText");
    ExitText = new Texture(0, 0, _renderer, "ExitText");

    return true;

}

void MainMenu::Render()
{
    SDL_RenderClear(_renderer);

    _destPlayTextRect.x = 340;
    _destPlayTextRect.y = 100;
    _destPlayTextRect.w = PlayText->widthPP * 4;
    _destPlayTextRect.h = PlayText->heigthPP * 4;

    _destRankTextRect.x = 300;
    _destRankTextRect.y = 200;
    _destRankTextRect.w = RankText->widthPP * 4;
    _destRankTextRect.h = RankText->heigthPP * 4;

    _destAudioTextRect.x = 325;
    _destAudioTextRect.y = 300;
    _destAudioTextRect.w = AudioText->widthPP * 4;
    _destAudioTextRect.h = AudioText->heigthPP * 4;

    _destExitTextRect.x = 350;
    _destExitTextRect.y = 400;
    _destExitTextRect.w = ExitText->widthPP * 4;
    _destExitTextRect.h = ExitText->heigthPP * 4;


    PlayText->Render(&_destPlayTextRect, 0);
    RankText->Render(&_destRankTextRect, 0);
    AudioText->Render(&_destAudioTextRect, 0);
    ExitText->Render(&_destExitTextRect, 0);
    ArrowText->Render(&_destArrowTextRect, 0);


    SDL_RenderPresent(_renderer);
}

void MainMenu::End()
{
    delete _logoTexture;
    delete PlayText;
    delete RankText;
    delete AudioText;
    delete ExitText;
    delete ArrowText;    
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

void MainMenu::InitSDL() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        throw SDL_Exception(SDL_GetError());
    }
}

void MainMenu::CreateWindowAndRender() {
    SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &_window, &_renderer);

    if (_window == nullptr || _renderer == nullptr) {
        throw SDL_Exception(SDL_GetError());
    }
}

//bool MainMenuScene::IsRunning() {
//    return _isRunning;
//}