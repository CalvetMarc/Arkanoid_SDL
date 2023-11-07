#include "Ball.h"

Ball::Ball(SDL_Renderer* renderer, double angle, int destBallRectX, int destBallRectY, int destBallRectW, int destBallRectH) : _renderer(renderer), _angle(angle)
{
    whoHitted = 1;

    _destBallRect.x = destBallRectX;
    _destBallRect.y = destBallRectY;
    _destBallRect.w = destBallRectW;
    _destBallRect.h = destBallRectH;

    sourceRect.w = 186;
    sourceRect.h = 185;


    ballSpeed = 2;

    vector.X = -1 * ballSpeed;
    vector.Y = -1 * ballSpeed;


    Pop1 = false;
    Pop2 = false;
}

void Ball::Init()
{
    _ballAnimation = new Animation("resources/ball.png", _renderer, _angle, sourceRect);

    _ballAnimation->Init();

    _ballXPosition = _destBallRect.x;

    _ballYPosition = _destBallRect.y;
}

void Ball::Update(double elapsedSeconds, Hero* hero1, Hero* hero2, Map* map, Serve GameServe)
{

    ballPosition.X = _ballXPosition;
    ballPosition.Y = _ballYPosition;

    if (Pop1) {
        Pop1 = false;
    }
    if (Pop2) {
        Pop2 = false;
    }


    if (GameServe == Serve::NO) {
        PlayerCollision(hero1, hero2);
        BrickCollision(map, hero1, hero2);
    }



    ComproveBounceAndRespawn(hero1, hero2, map, GameServe);

    UpdatePowerUps();


    _destBallRect.x = _ballXPosition;
    _destBallRect.y = _ballYPosition;

}

void Ball::Render()
{
    _ballAnimation->Render(&_destBallRect);
    for (auto item : mapPowerUps) {
        item->Render();
    }
}

void Ball::Release()
{
    _ballAnimation->Release();
    delete _ballAnimation;
}

void Ball::PlayerCollision(Hero* hero1, Hero* hero2)
{

    // Variables per comprovar posicio dels jugadors
    Vector2D<float>P1postion;
    P1postion.X = 45;
    P1postion.Y = hero1->_heroYPosition;
    Vector2D<float>P2postion;
    P2postion.X = 710;
    P2postion.Y = hero2->_heroYPosition;

    // Comprovar colissio amb player 
    if (CollisionsHelper::IsRectInsideRect(P1postion, ballPosition + vector, 20, 80, 18, 18)) {
        if (vector.X < 0)
            vector.X *= -1;
        whoHitted = 1;
        BounceSound();
    }
    else if (CollisionsHelper::IsRectInsideRect(P2postion, ballPosition + vector, 20, 80, 18, 18)) {
        if (vector.X > 0)
            vector.X *= -1;
        whoHitted = 2;
        BounceSound();
    };
}

void Ball::BrickCollision(Map* map, Hero* hero1, Hero* hero2)
{
    // Els blocks normals es comencen i acaben de trencar en updates diferents, i es guarden a aquest vector per anarse trencant
    for (auto it = UpdateNormalBrickAnimation.begin(); it != UpdateNormalBrickAnimation.end(); it++) {

        if (map->UpdateNormalB(*it) == false) {
            UpdateNormalBrickAnimation.erase(it);
        }
        break;
    }

    bool changeDone = false;

    //Es revisa la colisio amb els blocs, el vector te les posicions dels blocs carregats
    for (auto it = map->positions.begin(); it != map->positions.end(); it++) {

        if (CollisionsHelper::IsRectInsideRect(*it, ballPosition + vector, 20, 40, 18, 18)) {
            BounceSound();
            //float multi;
            if (vector.X < 0 && vector.Y < 0) {
                //Vector cap adalt a la esquerra

                if (ballPosition.Y > it->Y + 40) {
                    //Rebota per abaix                    
                    vector.Y *= -1;
                    changeDone = true;
                    if (map->isBrickNormal(map->ReturnIJ(it->X, it->Y))) {
                        UpdateNormalBrickAnimation.push_back(map->ReturnIJ(it->X, it->Y));
                    }
                    else {
                        map->UpdateBrick(it->X, it->Y);
                    }

                    if (map->CheckBrickPrintBool(it->X, it->Y) == false || map->isBrickNormal(map->ReturnIJ(it->X, it->Y)) == true) {
                        if (whoHitted == 1) {
                            hero1->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero1, *it);
                            }
                        }
                        else {
                            hero2->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero2, *it);
                            }
                        }
                        map->positions.erase(it);
                    }

                }
                else if (ballPosition.X > it->X + 20) {
                    //Rebota per la dreta                    
                    vector.X *= -1;
                    changeDone = true;
                    if (map->isBrickNormal(map->ReturnIJ(it->X, it->Y))) {
                        UpdateNormalBrickAnimation.push_back(map->ReturnIJ(it->X, it->Y));
                    }
                    else {
                        map->UpdateBrick(it->X, it->Y);
                    }

                    if (map->CheckBrickPrintBool(it->X, it->Y) == false || map->isBrickNormal(map->ReturnIJ(it->X, it->Y)) == true) {
                        if (whoHitted == 1) {
                            hero1->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero1, *it);
                            }
                        }
                        else {
                            hero2->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero2, *it);
                            }
                        }
                        map->positions.erase(it);
                    }
                }
                break;
            }
            if (vector.X > 0 && vector.Y < 0) {
                //Vector cap adalt a la dreta

                if (ballPosition.Y > it->Y + 40) {
                    //Rebota per abaix                    
                    vector.Y *= -1;
                    changeDone = true;
                    if (map->isBrickNormal(map->ReturnIJ(it->X, it->Y))) {
                        UpdateNormalBrickAnimation.push_back(map->ReturnIJ(it->X, it->Y));
                    }
                    else {
                        map->UpdateBrick(it->X, it->Y);
                    }
                    if (map->CheckBrickPrintBool(it->X, it->Y) == false || map->isBrickNormal(map->ReturnIJ(it->X, it->Y)) == true) {
                        if (whoHitted == 1) {
                            hero1->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero1, *it);
                            }
                        }
                        else {
                            hero2->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero2, *it);
                            }
                        }
                        map->positions.erase(it);
                    }
                }
                else if (ballPosition.X < it->X + 20) {
                    //Rebota per la esquerra                    
                    vector.X *= -1;
                    changeDone = true;
                    if (map->isBrickNormal(map->ReturnIJ(it->X, it->Y))) {
                        UpdateNormalBrickAnimation.push_back(map->ReturnIJ(it->X, it->Y));
                    }
                    else {
                        map->UpdateBrick(it->X, it->Y);
                    }
                    if (map->CheckBrickPrintBool(it->X, it->Y) == false || map->isBrickNormal(map->ReturnIJ(it->X, it->Y)) == true) {
                        if (whoHitted == 1) {
                            hero1->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero1, *it);
                            }
                        }
                        else {
                            hero2->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero2, *it);
                            }
                        }
                        map->positions.erase(it);
                    }
                }
                break;
            }
            if (vector.X > 0 && vector.Y > 0) {
                //Vector cap abaix a la dreta

                if (ballPosition.Y < it->Y) {
                    //Rebota per adalt                    
                    vector.Y *= -1;
                    changeDone = true;
                    if (map->isBrickNormal(map->ReturnIJ(it->X, it->Y))) {
                        UpdateNormalBrickAnimation.push_back(map->ReturnIJ(it->X, it->Y));
                    }
                    else {
                        map->UpdateBrick(it->X, it->Y);
                    }
                    if (map->CheckBrickPrintBool(it->X, it->Y) == false || map->isBrickNormal(map->ReturnIJ(it->X, it->Y)) == true) {
                        if (whoHitted == 1) {
                            hero1->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero1, *it);
                            }
                        }
                        else {
                            hero2->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero2, *it);
                            }
                        }
                        map->positions.erase(it);
                    }
                }
                else if (ballPosition.X < it->X) {
                    //Rebota per la esquerra                    
                    vector.X *= -1;
                    changeDone = true;
                    if (map->isBrickNormal(map->ReturnIJ(it->X, it->Y))) {
                        UpdateNormalBrickAnimation.push_back(map->ReturnIJ(it->X, it->Y));
                    }
                    else {
                        map->UpdateBrick(it->X, it->Y);
                    }
                    if (map->CheckBrickPrintBool(it->X, it->Y) == false || map->isBrickNormal(map->ReturnIJ(it->X, it->Y)) == true) {
                        if (whoHitted == 1) {
                            hero1->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero1, *it);
                            }
                        }
                        else {
                            hero2->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero2, *it);
                            }
                        }
                        map->positions.erase(it);
                    }
                }
                break;
            }
            if (vector.X < 0 && vector.Y > 0) {
                //Vector cap abaix a la esquerra

                if (ballPosition.Y < it->Y) {
                    //Rebota per adalt                    
                    vector.Y *= -1;
                    changeDone = true;
                    if (map->isBrickNormal(map->ReturnIJ(it->X, it->Y))) {
                        UpdateNormalBrickAnimation.push_back(map->ReturnIJ(it->X, it->Y));
                    }
                    else {
                        map->UpdateBrick(it->X, it->Y);
                    }
                    if (map->CheckBrickPrintBool(it->X, it->Y) == false || map->isBrickNormal(map->ReturnIJ(it->X, it->Y)) == true) {
                        if (whoHitted == 1) {
                            hero1->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero1, *it);
                            }
                        }
                        else {
                            hero2->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero2, *it);
                            }
                        }
                        map->positions.erase(it);
                    }
                }
                else if (ballPosition.X > it->X) {
                    //Rebota per la dreta                    
                    vector.X *= -1;
                    changeDone = true;
                    if (map->isBrickNormal(map->ReturnIJ(it->X, it->Y))) {
                        UpdateNormalBrickAnimation.push_back(map->ReturnIJ(it->X, it->Y));
                    }
                    else {
                        map->UpdateBrick(it->X, it->Y);
                    }
                    if (map->CheckBrickPrintBool(it->X, it->Y) == false || map->isBrickNormal(map->ReturnIJ(it->X, it->Y)) == true) {
                        if (whoHitted == 1) {
                            hero1->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero1, *it);
                            }
                        }
                        else {
                            hero2->_points += map->ReturnBrickPoints(it->X, it->Y);
                            if (map->ReturnIfBrickPowerUp(it->X, it->Y)) {
                                mapPowerUps.push_back(factory.Create(_renderer, map->ReturnPowerUpTime(it->X, it->Y)));
                                mapPowerUps.back()->Appear(hero2, *it);
                            }

                        }
                        map->positions.erase(it);
                    }
                }
                break;

            }
            if (changeDone) {
                break;
            }


        }
    }
}

void Ball::ComproveBounceAndRespawn(Hero* hero1, Hero* hero2, Map* map, Serve GameServe)
{
    float minDistance = 0;



    if (_ballYPosition < 35) {
        BounceSound();
        minDistance = 35 - (_ballYPosition + vector.Y);
        _ballYPosition += minDistance;
        vector.Y = vector.Y * -1;
    }
    else if (_ballYPosition + vector.Y > 443) {
        BounceSound();
        minDistance = (_ballYPosition + vector.Y) - 443;
        _ballYPosition += minDistance;
        vector.Y = vector.Y * -1;
    }
    else {
        if (GameServe == Serve::NO) {
            _ballYPosition += vector.Y;
        }
        else if (GameServe == Serve::P1) {
            _ballYPosition = hero1->_heroYPosition;
            vector.Y = 1 * ballSpeed;

        }
        else {
            _ballYPosition = hero2->_heroYPosition;
            vector.Y = 1 * ballSpeed;
        }
    }

    if (_ballXPosition >= 759) {
        Pop2 = true;
        _ballXPosition = 715;

    }
    else if (_ballXPosition <= 15) {
        Pop1 = true;
        _ballXPosition = 65;
    }
    else {
        if (GameServe == Serve::NO) {
            _ballXPosition += vector.X;
        }
        else if (GameServe == Serve::P1) {
            _ballXPosition = 65;
            vector.X = 1 * ballSpeed;
        }
        else {
            _ballXPosition = 715;
            vector.X = -1 * ballSpeed;
        }
    }
}

void Ball::UpdatePowerUps()
{

    int i = -1;
    for (PowerUp* item : mapPowerUps) {
        i++;
        if (item->ReturnDisappearState()) {
            item->Release();
            mapPowerUps.erase(mapPowerUps.begin() + i);
        }
        else {
            item->Update();
        }

    }
}

void Ball::BounceSound()
{

    // Audio::Instance(2)->PlayMusic(2,1);


}

void Ball::LoseLife()
{

}


