#include "OutputOperation.h"
#include "cstdio"

extern int winnerPoints;
extern std::map<int, std::string>gameRanking;

//
//OutputOperation::OutputOperation()
//{
//    std::stringstream empty;
//   std::stringstream information, information1, information2, information3, information4, information5, information6, information7, information8, information9;
//   size_t len, len1, len2, len3, len4, len5, len6, len7, len8, len9;
//   int position = 1, position1 = 2, position2 = 3, position3 = 4, position4 = 5, position5 = 6, position6 = 7, position7 = 8, position8 = 9, position9 = 10; 
//
//   information << "Raul";
//   len = information.str().size();
//   for (int i = 0; i < 20 - len;i++) {
//       information << ' ';
//   }
//   information << 300;
//   len = information.str().size();    
//
//   myFile.write(reinterpret_cast<char*>(&position), sizeof(int));//se guarda posicion
//   myFile.write(reinterpret_cast<char*>(&len), sizeof(size_t)); //se guarda el size    
//   myFile.write(information.str().c_str(), information.str().size());// se guarda el string
//
//   information1 << "Juan";
//   len1 = information1.str().size();
//   for (int i = 0; i < 20 - len1;i++) {
//       information1 << ' ';
//   }
//   information1 << 290;
//   len1 = information1.str().size();
//
//   myFile.write(reinterpret_cast<char*>(&position1), sizeof(int));//se guarda posicion
//   myFile.write(reinterpret_cast<char*>(&len1), sizeof(size_t)); //se guarda el size    
//   myFile.write(information.str().c_str(), information1.str().size());// se guarda el string
//
//   information2 << "Cristian";
//   len2 = information2.str().size();
//   for (int i = 0; i < 20 - len2;i++) {
//       information2 << ' ';
//   }
//   information2 << 280;
//   len2 = information2.str().size();
//
//   myFile.write(reinterpret_cast<char*>(&position2), sizeof(int));//se guarda posicion
//   myFile.write(reinterpret_cast<char*>(&len2), sizeof(size_t)); //se guarda el size    
//   myFile.write(information.str().c_str(), information2.str().size());// se guarda el string
//
//   information3 << "Pol";
//   len3 = information3.str().size();
//   for (int i = 0; i < 20 - len3;i++) {
//       information3 << ' ';
//   }
//   information3 << 270;
//   len3 = information3.str().size();
//
//   myFile.write(reinterpret_cast<char*>(&position3), sizeof(int));//se guarda posicion
//   myFile.write(reinterpret_cast<char*>(&len3), sizeof(size_t)); //se guarda el size    
//   myFile.write(information.str().c_str(), information3.str().size());// se guarda el string
//
//   information4 << "Uri";
//   len4 = information4.str().size();
//   for (int i = 0; i < 20 - len4;i++) {
//       information4 << ' ';
//   }
//   information4 << 260;
//   len4 = information4.str().size();
//
//   myFile.write(reinterpret_cast<char*>(&position4), sizeof(int));//se guarda posicion
//   myFile.write(reinterpret_cast<char*>(&len4), sizeof(size_t)); //se guarda el size    
//   myFile.write(information.str().c_str(), information4.str().size());// se guarda el string
//
//   information5 << "Biel";
//   len5 = information5.str().size();
//   for (int i = 0; i < 20 - len5;i++) {
//       information5 << ' ';
//   }
//   information5 << 250;
//   len5 = information5.str().size();
//
//   myFile.write(reinterpret_cast<char*>(&position5), sizeof(int));//se guarda posicion
//   myFile.write(reinterpret_cast<char*>(&len5), sizeof(size_t)); //se guarda el size    
//   myFile.write(information.str().c_str(), information5.str().size());// se guarda el string
//
//   information6 << "Paula";
//   len6 = information6.str().size();
//   for (int i = 0; i < 20 - len6;i++) {
//       information6 << ' ';
//   }
//   information6 << 240;
//   len6 = information6.str().size();
//
//   myFile.write(reinterpret_cast<char*>(&position6), sizeof(int));//se guarda posicion
//   myFile.write(reinterpret_cast<char*>(&len6), sizeof(size_t)); //se guarda el size    
//   myFile.write(information.str().c_str(), information6.str().size());// se guarda el string
//
//   information7 << "Maria";
//   len7 = information7.str().size();
//   for (int i = 0; i < 20 - len7;i++) {
//       information7 << ' ';
//   }
//   information7 << 230;
//   len7 = information7.str().size();
//
//   myFile.write(reinterpret_cast<char*>(&position7), sizeof(int));//se guarda posicion
//   myFile.write(reinterpret_cast<char*>(&len7), sizeof(size_t)); //se guarda el size    
//   myFile.write(information.str().c_str(), information7.str().size());// se guarda el string
//
//   information8 << "Jofe";
//   len8 = information8.str().size();
//   for (int i = 0; i < 20 - len8;i++) {
//       information8 << ' ';
//   }
//   information8 << 220;
//   len8 = information8.str().size();
//
//   myFile.write(reinterpret_cast<char*>(&position8), sizeof(int));//se guarda posicion
//   myFile.write(reinterpret_cast<char*>(&len8), sizeof(size_t)); //se guarda el size    
//   myFile.write(information.str().c_str(), information8.str().size());// se guarda el string
//
//   information9 << "Albert";
//   len9 = information9.str().size();
//   for (int i = 0; i < 20 - len9;i++) {
//       information9 << ' ';
//   }
//   information9 << 210;
//   len9 = information9.str().size();
//
//   myFile.write(reinterpret_cast<char*>(&position9), sizeof(int));//se guarda posicion
//   myFile.write(reinterpret_cast<char*>(&len9), sizeof(size_t)); //se guarda el size    
//   myFile.write(information.str().c_str(), information9.str().size());// se guarda el string
//}

OutputOperation::OutputOperation(const std::string path):FileAction(path)
{
}

void OutputOperation::Init(const std::string fileName)
{
    if (reWrite) {
        int position;
        size_t len;
        std::remove("resources/Ranking.bin");
        myFile.open(fileName, std::ios::out | std::ios::binary);
        for (int i = 1; i < 11;i++) {
            position = i;
            len = gameRanking[i].size();
            myFile.write(reinterpret_cast<char*>(&position), sizeof(int));
            myFile.write(reinterpret_cast<char*>(&len), sizeof(size_t));
            myFile.write(gameRanking[i].c_str(), gameRanking[i].size());            
        }
        myFile.close();
        reWrite = false;
    }
	
}

void OutputOperation::HandleEvents(bool& keepPlaying, GameStates& whichStates)
{
    char auxiliar;
   // bool keepWriting = true;
    SDL_Event event;
    std::stringstream aux;

    std::stringstream empty;
    
    while (SDL_PollEvent(&event)) {

        
        if (event.key.type == SDL_KEYDOWN)
        {
            if (!nameFilled) {
                auxiliar = CheckNameLetter(event);

                if (auxiliar == '&') {
                }
                else if (auxiliar == '/' && playerName.str().size() != 0) {
                    //keepWriting = false;
                    nameFilled = true;
                    //whichStates = GameStates::MENU;
                }
                else if (auxiliar == '-' && playerName.str().size() != 0) {

                    aux << playerName.str().substr(0, playerName.str().size() - 1);
                    playerName.swap(aux);
                    aux.swap(empty);
                }
                else if (playerName.str().size() < 15) {
                    playerName << auxiliar;
                }
            }
            else {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    whichStates = GameStates::MENU;
                }
            }

            
                                 
            
        }
        if (event.type == SDL_QUIT)
        {
            keepPlaying = false;
        }
    }
}

void OutputOperation::Update()
{
    /*for (int i = 1; i < 11; i++) {
        std::cout << gameRanking.find(i)->second << std::endl;
    }*/
    int arrayPuntos[10];
    for (int i = 0; i < 10; i++) {        
        std::string a;
        int number;
        int conversion[3];

        a = gameRanking[i + 1];

        conversion[0] = a.at(20)-48;
        conversion[1] = a.at(21)-48;
        conversion[2] = a.at(22)-48;

        number = (conversion[0] * 100) + (conversion[1] * 10) + conversion[2];

        arrayPuntos[i] = number;
                
    }
    int len = 0;

    if (nameFilled && !completed) {
        int position = 0;
        for (int i = 0;i < 10;i++) {
            if (winnerPoints > arrayPuntos[i]) {
                position = i + 1;
                break;
            }
        }
        if (position > 0 && !reWrite) {
            reWrite = true;
            len = playerName.str().size();
            for (int i = 0; i < 20 - len;i++) {
                playerName << " ";
            }
            playerName << winnerPoints;

            if (position == 10) {
                gameRanking[10] = playerName.str();
            }
            else {
                for (int i = 9;i >= position;i--) {
                    std::string auxiliar;
                    auxiliar = gameRanking[i];
                    gameRanking[i + 1] = auxiliar;
                }
                gameRanking[position] = playerName.str();
            }
            completed = true;
            Init("resources/Ranking.bin");
        }
    }
}

void OutputOperation::Render(SDL_Renderer* renderer)
{
    if (playerName.str().size() != 0) 
    name = new Texture(0, 0, renderer, playerName.str());
      
    title = new Texture(0, 0, renderer, "Ranking");
    putName = new Texture(0, 0, renderer, "Putname");

    _destTitle.x = 245;
    _destTitle.y = -50;
    _destTitle.w = 300;
    _destTitle.h = 275;

    _destPutName.x = 45;
    _destPutName.y = 200;
    _destPutName.w = 700;
    _destPutName.h = 100;

    _destName.x = 45;
    _destName.y = 350;
    _destName.w = playerName.str().size() * 30;
    _destName.h = 150;

    if (playerName.str().size() != 0)
    name->Render(&_destName, 0);

    title->Render(&_destTitle, 0);
    putName->Render(&_destPutName, 0);
}

void OutputOperation::End()
{
}

char OutputOperation::CheckNameLetter(SDL_Event event)
{
    if (event.key.keysym.sym == SDLK_a) {
        return 'a';
    }
    else if (event.key.keysym.sym == SDLK_b) {
        return 'b';
    }
    else if (event.key.keysym.sym == SDLK_c) {
        return 'c';
    }    
    else if (event.key.keysym.sym == SDLK_d) {
        return 'd';
    }
    else if (event.key.keysym.sym == SDLK_e) {
        return 'e';
    }
    else if (event.key.keysym.sym == SDLK_f) {
        return 'f';
    }
    else if (event.key.keysym.sym == SDLK_g) {
        return 'g';
    }
    else if (event.key.keysym.sym == SDLK_h) {
        return 'h';
    }
    else if (event.key.keysym.sym == SDLK_i) {
        return 'i';
    }
    else if (event.key.keysym.sym == SDLK_j) {
        return 'j';
    }
    else if (event.key.keysym.sym == SDLK_k) {
        return 'k';
    }
    else if (event.key.keysym.sym == SDLK_l) {
        return 'l';
    }
    else if (event.key.keysym.sym == SDLK_m) {
        return 'm';
    }
    else if (event.key.keysym.sym == SDLK_n) {
        return 'n';
    }
    else if (event.key.keysym.sym == SDLK_o) {
        return 'o';
    }
    else if (event.key.keysym.sym == SDLK_p) {
        return 'p';
    }
    else if (event.key.keysym.sym == SDLK_q) {
        return 'q';
    }
    else if (event.key.keysym.sym == SDLK_r) {
        return 'r';
    }
    else if (event.key.keysym.sym == SDLK_s) {
        return 's';
    }
    else if (event.key.keysym.sym == SDLK_t) {
        return 't';
    }
    else if (event.key.keysym.sym == SDLK_u) {
        return 'u';
    }
    else if (event.key.keysym.sym == SDLK_v) {
        return 'v';
    }
    else if (event.key.keysym.sym == SDLK_w) {
        return 'w';
    }
    else if (event.key.keysym.sym == SDLK_x) {
        return 'x';
    }
    else if (event.key.keysym.sym == SDLK_y) {
        return 'y';
    }
    else if (event.key.keysym.sym == SDLK_z) {
        return 'z';
    }
    else if (event.key.keysym.sym == SDLK_SPACE) {
        return ' ';
    }
    else if (event.key.keysym.sym == SDLK_RETURN) {
        return '/';
    }
    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
        return '-';
    }

    return '&';
}

   //std::stringstream empty;
   // std::stringstream information, information1, information2, information3, information4, information5, information6, information7, information8, information9;
   // size_t len, len1, len2, len3, len4, len5, len6, len7, len8, len9;
   // int position = 1, position1 = 2, position2 = 3, position3 = 4, position4 = 5, position5 = 6, position6 = 7, position7 = 8, position8 = 9, position9 = 10;

   // information << "Raul";
   // len = information.str().size();
   // for (int i = 0; i < 20 - len;i++) {
   //     information << ' ';
   // }
   // information << 300;
   // len = information.str().size();

   // myFile.write(reinterpret_cast<char*>(&position), sizeof(int));//se guarda posicion
   // myFile.write(reinterpret_cast<char*>(&len), sizeof(size_t)); //se guarda el size    
   // myFile.write(information.str().c_str(), information.str().size());// se guarda el string

   // information1 << "Juan";
   // len1 = information1.str().size();
   // for (int i = 0; i < 20 - len1;i++) {
   //     information1 << ' ';
   // }
   // information1 << 290;
   // len1 = information1.str().size();

   // myFile.write(reinterpret_cast<char*>(&position1), sizeof(int));//se guarda posicion
   // myFile.write(reinterpret_cast<char*>(&len1), sizeof(size_t)); //se guarda el size    
   // myFile.write(information1.str().c_str(), information1.str().size());// se guarda el string

   // information2 << "Cristian";
   // len2 = information2.str().size();
   // for (int i = 0; i < 20 - len2;i++) {
   //     information2 << ' ';
   // }
   // information2 << 280;
   // len2 = information2.str().size();

   // myFile.write(reinterpret_cast<char*>(&position2), sizeof(int));//se guarda posicion
   // myFile.write(reinterpret_cast<char*>(&len2), sizeof(size_t)); //se guarda el size    
   // myFile.write(information2.str().c_str(), information2.str().size());// se guarda el string

   // information3 << "Pol";
   // len3 = information3.str().size();
   // for (int i = 0; i < 20 - len3;i++) {
   //     information3 << ' ';
   // }
   // information3 << 270;
   // len3 = information3.str().size();

   // myFile.write(reinterpret_cast<char*>(&position3), sizeof(int));//se guarda posicion
   // myFile.write(reinterpret_cast<char*>(&len3), sizeof(size_t)); //se guarda el size    
   // myFile.write(information3.str().c_str(), information3.str().size());// se guarda el string

   // information4 << "Uri";
   // len4 = information4.str().size();
   // for (int i = 0; i < 20 - len4;i++) {
   //     information4 << ' ';
   // }
   // information4 << 260;
   // len4 = information4.str().size();

   // myFile.write(reinterpret_cast<char*>(&position4), sizeof(int));//se guarda posicion
   // myFile.write(reinterpret_cast<char*>(&len4), sizeof(size_t)); //se guarda el size    
   // myFile.write(information4.str().c_str(), information4.str().size());// se guarda el string

   // information5 << "Biel";
   // len5 = information5.str().size();
   // for (int i = 0; i < 20 - len5;i++) {
   //     information5 << ' ';
   // }
   // information5 << 250;
   // len5 = information5.str().size();

   // myFile.write(reinterpret_cast<char*>(&position5), sizeof(int));//se guarda posicion
   // myFile.write(reinterpret_cast<char*>(&len5), sizeof(size_t)); //se guarda el size    
   // myFile.write(information5.str().c_str(), information5.str().size());// se guarda el string

   // information6 << "Paula";
   // len6 = information6.str().size();
   // for (int i = 0; i < 20 - len6;i++) {
   //     information6 << ' ';
   // }
   // information6 << 240;
   // len6 = information6.str().size();

   // myFile.write(reinterpret_cast<char*>(&position6), sizeof(int));//se guarda posicion
   // myFile.write(reinterpret_cast<char*>(&len6), sizeof(size_t)); //se guarda el size    
   // myFile.write(information6.str().c_str(), information6.str().size());// se guarda el string

   // information7 << "Maria";
   // len7 = information7.str().size();
   // for (int i = 0; i < 20 - len7;i++) {
   //     information7 << ' ';
   // }
   // information7 << 230;
   // len7 = information7.str().size();

   // myFile.write(reinterpret_cast<char*>(&position7), sizeof(int));//se guarda posicion
   // myFile.write(reinterpret_cast<char*>(&len7), sizeof(size_t)); //se guarda el size    
   // myFile.write(information7.str().c_str(), information7.str().size());// se guarda el string

   // information8 << "Jofe";
   // len8 = information8.str().size();
   // for (int i = 0; i < 20 - len8;i++) {
   //     information8 << ' ';
   // }
   // information8 << 220;
   // len8 = information8.str().size();

   // myFile.write(reinterpret_cast<char*>(&position8), sizeof(int));//se guarda posicion
   // myFile.write(reinterpret_cast<char*>(&len8), sizeof(size_t)); //se guarda el size    
   // myFile.write(information8.str().c_str(), information8.str().size());// se guarda el string

   // information9 << "Albert";
   // len9 = information9.str().size();
   // for (int i = 0; i < 20 - len9;i++) {
   //     information9 << ' ';
   // }
   // information9 << 210;
   // len9 = information9.str().size();

   // myFile.write(reinterpret_cast<char*>(&position9), sizeof(int));//se guarda posicion
   // myFile.write(reinterpret_cast<char*>(&len9), sizeof(size_t)); //se guarda el size    
   // myFile.write(information9.str().c_str(), information9.str().size());// se guarda el string
   //