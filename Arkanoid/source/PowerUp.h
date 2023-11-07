#pragma once
#include "Hero.h"
#include "Vector2D.h"
#include "Engine/Graphics/Animation.h"
#include <SDL_render.h>
#include "CollisionsHelper.h"
#include "GameInfo.h"
#include <chrono>
#include <iostream>

class PowerUp
{
public:
	PowerUp() = default;
	virtual void Appear(Hero * player, Vector2D<float>position) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Activate() = 0;
	virtual bool PlayerCollision() = 0;
	virtual void Release() = 0;
	virtual bool ReturnDisappearState() = 0;
	virtual void ControlTime() = 0;
	virtual void ResetPower() = 0;
	virtual void ResetOtherPowers() = 0;
};

