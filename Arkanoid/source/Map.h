#pragma once
#include <vector>
#include <iostream>
#include <SDL_render.h>
#include "Brick.h"
#include "Vector2D.h"
#include <deque>
#include "GameInfo.h"




class Texture;
class Animation;
class Controller;



class Map
{
public:

	std::vector<Vector2D<float>>positions;
	Map(SDL_Renderer* renderer);
	void Init();
	void Update();
	void Render();
	/*BrickType CharToBrick(char a);*/
	void UpdateBrick(float brickPx, float brickPy);
	bool UpdateNormalB(Vector2D<float>IJ);
	bool CheckBrickPrintBool(float brickPx, float brickPy);
	bool ReturnIfBrickPowerUp(float brickPx, float brickPy);
	int ReturnBrickPoints(float brickPx, float brickPy);
	int ReturnPowerUpTime(float brickPx, float brickPy);
	Vector2D<float> ReturnIJ(float brickPx, float brickPy);
	bool isBrickNormal(Vector2D<float>IJ);
private:
	Brick map[11][12];
	//Brick** ptr;
	SDL_Renderer* _renderer;
	void PrintMap();
	void LoadMap(GameInfo mapInformation);
};

