#include "Engine/Graphics/Animation.h"
#include "Engine/Input/Controller.h"
#include "Hero.h"
#include <iostream>
#include "../dependencies/XML/rapidxml.hpp"
#include "../dependencies/XML/rapidxml_utils.hpp"
#include "../dependencies/XML/rapidxml_iterators.hpp"
#include "../dependencies/XML/rapidxml_print.hpp"
#include <sstream>


const int UP = 1;
const int DOWN = 2;

Hero::Hero(SDL_Renderer* renderer, Controller* controller, double angle, int destHeroRectX, int destHeroRectY, int destHeroRectW, int destHeroRectH, int heroXPos
) : _renderer(renderer), _controller(controller), _angle(angle){

    _points = 0;

    up = false;
    down = false;

    _destHeroRect.x = destHeroRectX;
    _heroXPosition = destHeroRectX;
    _destHeroRect.y = destHeroRectY;
    _destHeroRect.w = destHeroRectW;
    _destHeroRect.h = destHeroRectH;
        
    
}

void Hero::Init() {

        
    rapidxml::xml_document<> doc;
    std::ifstream file("resources/config.xml"); //"../../res/files/BookStore.xml");

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);
        
    rapidxml::xml_node<>* pRoot = doc.first_node();

    rapidxml::xml_attribute<>* pattr;
    
    rapidxml::xml_node<>* pNode = pRoot->first_node("Level");
     
    char* pointer = pNode->name() - 48;
    speed = (int)*pointer-48;

    originalSpeed = speed;
    originalWidth = _destHeroRect.w;


    sourceRect.w = 60;
    sourceRect.h = 20;
    _heroAnimation = new Animation("resources/platform.png", _renderer,_angle,sourceRect);  

   _heroAnimation->Init();

  
   /*
    _destHeroRect.x = 10;
    _destHeroRect.y = 300;
    _destHeroRect.w = 80;
    _destHeroRect.h = 20;
   */
   _heroYPosition = _destHeroRect.y;
}

void Hero::Update(double elapsedSeconds) {
   // _heroYPosition = _destHeroRect.y;
    if (down && _destHeroRect.y < 419) {
        if (_destHeroRect.y < 419) {
            _heroYPosition += speed;//* elapsedSeconds;
            _destHeroRect.y = _heroYPosition;
           // calculo = _destHeroRect.y;
            if (_destHeroRect.y > 419) {
                _destHeroRect.y = 419;
            }
            
        }
        else {
            down = false;
        }
        
    }
    if (up && _destHeroRect.y > 60) {
        if (_destHeroRect.y > 60) {
            _heroYPosition -= speed; //* elapsedSeconds;
            _destHeroRect.y = _heroYPosition;
            if (_destHeroRect.y < 60) {
                _destHeroRect.y = 60;
            }
           
        }
        else {
            up = false;
        }


        //_controller->ResetEvents();
        //std::cout << _destHeroRect.y;
    }
  
}

void Hero::MoveUp() {
    up = true;
    down = false;
}
void Hero::MoveDown() {
    down = true;
    up = false;
}

void Hero::PutUpOff()
{
    up = false;
}

void Hero::PutDownOff()
{
    down = false;
}

void Hero::Render() {
   /* _livesRect.x = 75;
    _livesRect.y = 550;
    _livesRect.w = 80;
    _livesRect.h = 20;*/

   
    

   /* _livesRect2.x = 459;
    _livesRect2.y = 550;
    _livesRect2.w = 80;
    _livesRect2.h = 20;*/

   

    _heroAnimation->Render(&_destHeroRect);
}

void Hero::Release() {
    _heroAnimation->Release();
    delete _heroAnimation;

}




