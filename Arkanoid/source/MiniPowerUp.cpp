#include "MiniPowerUp.h"

MiniPowerUp::MiniPowerUp(SDL_Renderer* renderer, int timeActive):_renderer(renderer),_timeActive(timeActive)
{
	SDL_Rect sourceRect;

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = 483;
	sourceRect.h = 479;

	_destPowerUp.w = 45;
	_destPowerUp.h = 45;

	percentSmaller = 25;
	disappear = false;

	_animation = new Animation("resources/miniseta.png", _renderer, 0, sourceRect);
	_animation->Init();
}

void MiniPowerUp::Appear(Hero* player, Vector2D<float> position)
{
	_followHero = player;
	_destPowerUp.x = position.X;
	_destPowerUp.y = position.Y;

	powerUpXPosition = _destPowerUp.x;
	//Render();
}

void MiniPowerUp::Update()
{
	vectorForCollisionPU.X = powerUpXPosition;
	vectorForCollisionPU.Y = _destPowerUp.y;

	vectorForCollisionPlayer.X = _followHero->_heroXPosition;
	vectorForCollisionPlayer.Y = _followHero->_heroYPosition;

	if (active) {
		ControlTime();
	}
	else if (powerUpXPosition < 10 || powerUpXPosition > 759) {
		disappear = true;
		//Release();
	}
	else if (PlayerCollision()) {

		Activate();		
		//Release();
	}
	else {
		if (_followHero->_heroXPosition < 400) {
			powerUpXPosition--;
		}
		else {
			powerUpXPosition++;
		}
	}

	_destPowerUp.x = powerUpXPosition;

	//Render();
}

void MiniPowerUp::Render()
{
	if (!active) {
		_animation->Render(&_destPowerUp);
	}
}

void MiniPowerUp::Activate()
{
	ResetOtherPowers();
	_followHero->simultanyPowerUps += 1;
	active = true;
	start = std::chrono::high_resolution_clock::now();
	originalSize = _followHero->_destHeroRect.w;
	float operation = _followHero->_destHeroRect.w * (percentSmaller / 100);
	_followHero->_destHeroRect.w  -= percentSmaller;
}

bool MiniPowerUp::PlayerCollision()
{
	if (CollisionsHelper::IsRectInsideRect(vectorForCollisionPU, vectorForCollisionPlayer, _destPowerUp.w, _destPowerUp.h, _followHero->_destHeroRect.w, _followHero->_destHeroRect.h)) {

		return true;
	}
	else {
		return false;
	}
}

void MiniPowerUp::Release()
{
	_animation->Release();
	delete this;
}

bool MiniPowerUp::ReturnDisappearState()
{
	return disappear;
}

void MiniPowerUp::ControlTime()
{
	std::chrono::steady_clock::time_point stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
	if (duration.count() >= _timeActive) {
		ResetPower();
	}
	else {
		//std::cout << duration.count() << std::endl;
	}
}

void MiniPowerUp::ResetPower()
{
	if (_followHero->simultanyPowerUps == 1) {
		_followHero->_destHeroRect.w = _followHero->originalWidth;
	}
	_followHero->simultanyPowerUps -= 1;
	disappear = true;
}

void MiniPowerUp::ResetOtherPowers()
{
	_followHero->speed = _followHero->originalSpeed;
	_followHero->_destHeroRect.w = _followHero->originalWidth;
}
