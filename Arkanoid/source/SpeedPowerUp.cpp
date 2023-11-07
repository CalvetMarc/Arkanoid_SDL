#include "SpeedPowerUp.h"

SpeedPowerUp::SpeedPowerUp(SDL_Renderer* renderer, int timeActive):_renderer(renderer),_timeActive(timeActive)
{
	SDL_Rect sourceRect;

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = 512;
	sourceRect.h = 512;

	_destPowerUp.w = 45;
	_destPowerUp.h = 45;

	percentFaster = 20;
	disappear = false;

	_animation = new Animation("resources/speed.png", _renderer, 0, sourceRect);
	_animation->Init();
}

void SpeedPowerUp::Appear(Hero* player, Vector2D<float> position)
{
	_followHero = player;
	_destPowerUp.x = position.X;
	_destPowerUp.y = position.Y;

	powerUpXPosition = _destPowerUp.x;
	//Render();
}

void SpeedPowerUp::Update()
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
	
}

void SpeedPowerUp::Render()
{
	if (!active) {
		_animation->Render(&_destPowerUp);
	}
}

void SpeedPowerUp::Activate()
{
	ResetOtherPowers();
	_followHero->simultanyPowerUps += 1;
	active = true;
	start = std::chrono::high_resolution_clock::now();
	originalSpeed = _followHero->speed;
	float operation = _followHero->speed * (percentFaster / 100);
	_followHero->speed += percentFaster;

}

bool SpeedPowerUp::PlayerCollision()
{
	if (CollisionsHelper::IsRectInsideRect(vectorForCollisionPU, vectorForCollisionPlayer, _destPowerUp.w, _destPowerUp.h, _followHero->_destHeroRect.w, _followHero->_destHeroRect.h)) {

		return true;
	}
	else {
		return false;
	}
}

void SpeedPowerUp::Release()
{
	_animation->Release();
	delete this;
}

bool SpeedPowerUp::ReturnDisappearState()
{
	return disappear;
}

void SpeedPowerUp::ControlTime()
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

void SpeedPowerUp::ResetPower()
{
	if (_followHero->simultanyPowerUps == 1) {
		_followHero->speed = _followHero->originalSpeed;
	}
	_followHero->simultanyPowerUps -= 1;
	disappear = true;
	
}

void SpeedPowerUp::ResetOtherPowers()
{
	_followHero->speed = _followHero->originalSpeed;
	_followHero->_destHeroRect.w = _followHero->originalWidth;
}
