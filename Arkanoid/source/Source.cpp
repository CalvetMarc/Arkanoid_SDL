#include <SDL.h>
#include <cstdio>
#include "Game.h"
#include <exception>
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "../dependencies/XML/rapidxml.hpp"
#include "../dependencies/XML/rapidxml_utils.hpp"
#include "../dependencies/XML/rapidxml_iterators.hpp"
#include "../dependencies/XML/rapidxml_print.hpp"
#include <SDL_ttf.h>
#include <time.h>
#include "GameManager.h"
#include "OutputOperation.h"




int main(int argc, char* args[]) {

    srand(time(NULL));
    TTF_Init();   
    GameManager * gameM = new GameManager();
    bool keepPlaying = true;

    try {
        do{
            gameM->Init();

            while (!gameM->changeGameStates && keepPlaying) {

                gameM->Update(keepPlaying);

            }        
            gameM->Release();

        } while (keepPlaying);
        
    }
    catch (std::exception& exception) {
        fprintf(stderr, "%s", exception.what());
        SDL_Quit();
        return -1;
    }

    return 0;
}

