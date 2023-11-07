
#include "Map.h"
#include "Engine/Graphics/Animation.h"
#include "../dependencies/XML/rapidxml.hpp"
#include "../dependencies/XML/rapidxml_utils.hpp"
#include "../dependencies/XML/rapidxml_iterators.hpp"
#include "../dependencies/XML/rapidxml_print.hpp"
#include <sstream>


Map::Map(SDL_Renderer* renderer) :_renderer(renderer)
{
    GameInfo* _mapInformation = new GameInfo(_renderer);// _mapInformation(_renderer);

    LoadMap(*_mapInformation);

};


void Map::Init()
{


}

void Map::Update()
{
}

void Map::Render()
{
    PrintMap();

}


void Map::UpdateBrick(float brickPx, float brickPy)
{

    int i = (brickPy + 5) / 40;
    int j = (brickPx - 271) / 20;
    map[i][j].Update();
}

bool Map::UpdateNormalB(Vector2D<float> IJ)
{
    return map[(int)IJ.X][(int)IJ.Y].UpdateNormalBrickXAnim();
}

bool Map::CheckBrickPrintBool(float brickPx, float brickPy)
{

    int i = (brickPy + 5) / 40;
    int j = (brickPx - 271) / 20;
    return map[i][j].Print;
}

bool Map::ReturnIfBrickPowerUp(float brickPx, float brickPy)
{
    int i = (brickPy + 5) / 40;
    int j = (brickPx - 271) / 20;
    return map[i][j]._powerUp;
}

int Map::ReturnBrickPoints(float brickPx, float brickPy)
{
    int i = (brickPy + 5) / 40;
    int j = (brickPx - 271) / 20;
    return map[i][j]._currentBrickScore;

}

int Map::ReturnPowerUpTime(float brickPx, float brickPy)
{
    int i = (brickPy + 5) / 40;
    int j = (brickPx - 271) / 20;

    return  map[i][j]._timePUActive;
}

Vector2D<float> Map::ReturnIJ(float brickPx, float brickPy)
{
    Vector2D<float>IJpositions;
    float i = (brickPy + 5) / 40;
    float j = (brickPx - 271) / 20;
    IJpositions.X = i;
    IJpositions.Y = j;
    return IJpositions;

}

bool Map::isBrickNormal(Vector2D<float>IJ)
{
    if (map[(int)IJ.X][(int)IJ.Y]._type == BrickType::N) {
        return true;
    }
    else {
        return false;
    }

}

void Map::PrintMap()
{


    for (int i = 0; i < 11; i++) {
        //ptr = map[i];
        for (int j = 0; j < 12; j++) {
            //ptr[i] = map[i][j];
            if (map[i][j].Print) {
                map[i][j].Render();
            }

        }
    }
}

void Map::LoadMap(GameInfo mapInformation)
{
    Vector2D<int>mapPositions;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 12; j++) {
            mapPositions.X = i;
            mapPositions.Y = j;
            map[i][j] = mapInformation.ChargeMap(mapPositions);
        }
    }
    mapInformation.CopyPositionsVector(positions);
}
