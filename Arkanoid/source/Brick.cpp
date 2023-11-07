#include "Brick.h"
//#include "Engine/Graphics/Animation.h"
//#include <iostream>
#include "../dependencies/XML/rapidxml.hpp"
#include "../dependencies/XML/rapidxml_utils.hpp"
#include "../dependencies/XML/rapidxml_iterators.hpp"
#include "../dependencies/XML/rapidxml_print.hpp"
#include <sstream>

Brick::Brick()
{
    Print = false;
}

Brick::Brick(SDL_Renderer* renderer, double angle, int destBrickRectX, int destBrickRectY, int destBrickRectW, int destBrickRectH, int brickXPos, BrickType type, bool powerUp, int timePUActive)
    : _renderer(renderer), _angle(angle), _type(type), _powerUp(powerUp), _timePUActive(timePUActive)
{
    Print = true;
    _destBrickRect.x = destBrickRectX;
    _destBrickRect.y = destBrickRectY;
    _destBrickRect.w = 40;
    _destBrickRect.h = 20;

   // _brickXPosition = brickXPos;

    switch (_type)
    {
    case BrickType::F:
        _sourceRect.x = 0;
        _sourceRect.y = 40;
        Init();       
        break;
    case BrickType::N:
        _sourceRect.x = 0;
        _sourceRect.y = 0;
        Init();        
        SetMaxMinWhenBreakN(_minScoreWhenBreak,_maxScoreWhenBreak);    
        _hitsLeftToBreak = 1;
        break;
    case BrickType::H:
        _sourceRect.x = 0;
        _sourceRect.y = 20;
        Init();        
        SetMaxMinWhenBreakH(_minScoreWhenBreak, _maxScoreWhenBreak);
        _hitsLeftToBreak = 3;
        break;
    default:
        break;
    }

    if (_type != BrickType::F) {
        _currentBrickScore = rand() % _maxScoreWhenBreak + _minScoreWhenBreak;
        int probability = rand() % _maxScoreWhenBreak + _minScoreWhenBreak;
    }
       

    
}

void Brick::Init()
{
    //_brickAnimation = new Animation("resources/platform.png", _renderer, 10, 1, 707, 587, _angle);

    _sourceRect.w = 40;
    _sourceRect.h = 20;
    _brickAnimation = new Animation("resources/bricks.jpg", _renderer, _angle,_sourceRect);

    _brickAnimation->Init();
    //Render();
}

void Brick::Update()
{
    
    //_brickAnimation->SetSourceRect()
    if (_type != BrickType::F) {
        _hitsLeftToBreak--;
    }    
    if (_hitsLeftToBreak <= 0 && _type != BrickType::F) {
        if (_type != BrickType::N) {
            Print = false;
        }
        /*else {
            
        }*/
        
    }
    if (_type == BrickType::H && Print) {
        _brickAnimation->Release();
        delete _brickAnimation;
        /*_brickAnimation->Release(); 
        delete _brickAnimation;*/
        _sourceRect.x += 80;
        //_sourceRect.x += 40;

        _brickAnimation = new Animation("resources/bricks.jpg", _renderer, _angle, _sourceRect);
        _brickAnimation->Init();
    }
    if (_type == BrickType::F) {
        _brickAnimation->Release();
        delete _brickAnimation;
        _sourceRect.x += 40;
        _sourceRect.x = _sourceRect.x % 200;
        //_sourceRect.x += 40;

        _brickAnimation = new Animation("resources/bricks.jpg", _renderer, _angle, _sourceRect);
        _brickAnimation->Init();

    }
}

void Brick::SetMaxMinWhenBreakN(int& minScoreWhenBreak, int& maxScoreWhenBreak)
{
    rapidxml::xml_document<> doc;
    std::ifstream file("resources/config.xml"); 
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);


    rapidxml::xml_node<>* pRoot = doc.first_node();    
    rapidxml::xml_node<>* pNodee = pRoot->first_node("BrickInfo");
    rapidxml::xml_node<>* pNodeII = pNodee->first_node(); 

    

   char* minScore = pNodeII->first_attribute()->value(); //aixo es el valor de min
   char* maxScore = pNodeII->last_attribute()->value(); //aixo es el valor de max

   minScoreWhenBreak = *minScore - 48;
   maxScoreWhenBreak = *maxScore - 48;

   return;

}

void Brick::SetMaxMinWhenBreakH(int& minScoreWhenBreak, int& maxScoreWhenBreak)
{
    rapidxml::xml_document<> doc;
    std::ifstream file("resources/config.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);


    rapidxml::xml_node<>* pRoot = doc.first_node();    
    rapidxml::xml_node<>* pNodee = pRoot->first_node("BrickInfo");
    rapidxml::xml_node<>* pNodeII = pNodee->first_node();

    pNodeII = pNodeII->next_sibling();

    char* minScore = pNodeII->first_attribute()->value(); //aixo es el valor de min
    char* maxScore = pNodeII->last_attribute()->value(); //aixo es el valor de max

    minScoreWhenBreak = *minScore - 48;
    maxScoreWhenBreak = *maxScore - 48;

    return;
}

bool Brick::UpdateNormalBrickXAnim()
{
    if (_sourceRect.x < 200) {
        _sourceRect.x += 40;
        _brickAnimation->Release();
        delete _brickAnimation;  
        _brickAnimation = new Animation("resources/bricks.jpg", _renderer, _angle, _sourceRect);
        _brickAnimation->Init();

        if (_sourceRect.x < 200) {
            return true;
        }
        else {
            return false;
            _hitsLeftToBreak = 0;
            Print = false;
        }        
    }
    else {
        return false;
        _hitsLeftToBreak = 0;
        Print = false;
    }
    
}

void Brick::Release()
{
    _brickAnimation->Release();
    delete _brickAnimation;
}

void Brick::Render() {
    _brickAnimation->Render(&_destBrickRect);
}
