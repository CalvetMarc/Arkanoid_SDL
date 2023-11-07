#include "InputOperation.h"

extern std::map<int, std::string>gameRanking;

InputOperation::InputOperation(const std::string path) :FileAction(path)
{
	/*myFile.open(fileName, std::ios::in | std::ios::binary);

	size_t size = 0;
	int position = 0;
	std::string content;
	for (int i = 0; i < 10;i++) {
		myFile.read(reinterpret_cast<char*>(&position), sizeof(int));
		myFile.read(reinterpret_cast<char*>(&size), sizeof(size_t));
		char* temp = new char[size + 1];
		myFile.read(temp, size);
		temp[size] = '\0';
		content = temp;
		temp = nullptr;
		delete[]temp;
		gameRanking.insert(std::make_pair(position,content));
		content.clear();
	}

	myFile.close();*/
}

void InputOperation::Init(const std::string fileName)
{
	
}

void InputOperation::HandleEvents(bool& keepPlaying, GameStates& whichStates)
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		if (event.key.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				whichStates = GameStates::MENU;
			}
			
			
		}
		if (event.type == SDL_QUIT)
		{
			keepPlaying = false;
		}
	}
}

void InputOperation::Update()
{

}

void InputOperation::Render(SDL_Renderer* renderer)
{
	std::stringstream empty;
	std::stringstream fillTexture, fillTexture1, fillTexture2, fillTexture3, fillTexture4, fillTexture5, fillTexture6, fillTexture7, fillTexture8, fillTexture9;

	title = new Texture(0, 0, renderer, "Ranking");
	_destTitle.x = 245;
	_destTitle.y = -50;
	_destTitle.w = 300;
	_destTitle.h = 275;


	fillTexture << "1- " << gameRanking[1];
	player1 = new Texture(0, 0, renderer, fillTexture.str());
	_dest1.x = 45;
	_dest1.y = 210;
	_dest1.w = 300;
	_dest1.h = 80;

	
	fillTexture1 << "2- " << gameRanking[2];
	player2 = new Texture(0, 0, renderer, fillTexture1.str());
	_dest2.x = 45;
	_dest2.y = 280;
	_dest2.w = 300;
	_dest2.h = 80;
	
	
	fillTexture2 << "3- " << gameRanking[3];
	player3 = new Texture(0, 0, renderer, fillTexture2.str());
	_dest3.x = 45;
	_dest3.y = 350;
	_dest3.w = 300;
	_dest3.h = 80;

	
	fillTexture3 << "4- " << gameRanking[4];
	player4 = new Texture(0, 0, renderer, fillTexture3.str());
	_dest4.x = 45;
	_dest4.y = 420;
	_dest4.w = 300;
	_dest4.h = 80;

	
	fillTexture4 << "5- " << gameRanking[5];
	player5 = new Texture(0, 0, renderer, fillTexture4.str());
	_dest5.x = 45;
	_dest5.y = 490;
	_dest5.w = 300;
	_dest5.h = 80;

	
	fillTexture5 << "6- " << gameRanking[6];
	player6 = new Texture(0, 0, renderer, fillTexture5.str());
	_dest6.x = 430;
	_dest6.y = 210;
	_dest6.w = 300;
	_dest6.h = 80;

	
	fillTexture6 << "7- " << gameRanking[7];
	player7 = new Texture(0, 0, renderer, fillTexture6.str());
	_dest7.x = 430;
	_dest7.y = 280;
	_dest7.w = 300;
	_dest7.h = 80;

	
	fillTexture7 << "8- " << gameRanking[8];
	player8 = new Texture(0, 0, renderer, fillTexture7.str());
	_dest8.x = 430;
	_dest8.y = 350;
	_dest8.w = 300;
	_dest8.h = 80;

	
	fillTexture8 << "9- " << gameRanking[9];
	player9 = new Texture(0, 0, renderer, fillTexture8.str());
	_dest9.x = 430;
	_dest9.y = 420;
	_dest9.w = 300;
	_dest9.h = 80;

	
	fillTexture9 << "10- " << gameRanking[10];
	player10 = new Texture(0, 0, renderer, fillTexture9.str());
	_dest10.x = 430;
	_dest10.y = 490;
	_dest10.w = 300;
	_dest10.h = 80;

	title->Render(&_destTitle, 0);
	player1->Render(&_dest1, 0);
	player2->Render(&_dest2, 0);	
	player3->Render(&_dest3, 0);
	player4->Render(&_dest4, 0);
	player5->Render(&_dest5, 0);
	player6->Render(&_dest6, 0);
	player7->Render(&_dest7, 0);
	player8->Render(&_dest8, 0);
	player9->Render(&_dest9, 0);
	player10->Render(&_dest10, 0);

}

void InputOperation::End()
{
	
}
