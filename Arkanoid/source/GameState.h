#pragma once


enum class GameStates{ SPLASHSCREEN,MENU,GAME,RANKINGWRITE,RANKINGREAD};
enum class PlayingStates{STARTGAME,RUNNING,PAUSED,GAMEOVER};

//int winnerPoints;

class GameState
{

public:
	GameState() = default;
	virtual void Start(GameStates& whichStates) = 0;
	virtual void HandleEvents(bool& keepPlaying, GameStates& whichStates) = 0;
	virtual bool Update(double elapsedTime) = 0;
	virtual void Render() = 0;
	virtual void End() = 0;
	//int winnerPoints;
};
