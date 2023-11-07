#include "GameInfo.h"
#include <iostream>


Brick GameInfo::ChargeMap(Vector2D<int> positionsToLoad)
{       

    return _map[positionsToLoad.X][positionsToLoad.Y];     
}

GameInfo::GameInfo(SDL_Renderer* _renderer) {

    PowerUpsInformation();
    FillMap(_renderer);    
}

void GameInfo::CopyPositionsVector(std::vector<Vector2D<float>>& _positions)
{
    _positions.resize(positions.size());
    for (auto it = positions.begin(); it != positions.end(); it++) {
        _positions.push_back(*it);
    }
}

BrickType GameInfo::CharToBrick(char a)
{
    switch (a)
    {
    case 'N':
        return BrickType::N;
        break;
        
    case 'H':
        return BrickType::H;
        break;
        
    case 'F':
        return BrickType::F;
        break;
        
    default:
        break;
    }
        
    return BrickType::F;
}

void GameInfo::FillMap(SDL_Renderer* _renderer)
{
    BrickType type;
    char typeC;
    //type = static_cast<BrickType>(typeC);


    rapidxml::xml_document<> doc;
    std::ifstream file("resources/config.xml"); //"../../res/files/BookStore.xml");

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);

    /*std::cout << "Nombre de la raíz: " << doc.first_node()->name() << "\n";
    std::cout << "Value: " << (std::string)doc.first_node()->value() << "\n";*/

    rapidxml::xml_node<>* pRoot = doc.first_node();

    rapidxml::xml_attribute<>* pattr;

    rapidxml::xml_node<>* pNodee = pRoot->first_node("BrickInfo");

    rapidxml::xml_node<>* pNodeII = pNodee->first_node();

    for (rapidxml::xml_node<>* pNode = pRoot->first_node("Level"); pNode; pNode = pNode->next_sibling()) {


        //std::cout << "this should say something\n";
        //std::cout << pNode->name();



        for (rapidxml::xml_node<>* pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {

            //std::cout << "      " << pNodeI->name() << " : "; //this says the type of block and follows up with : always says brick
            int i;
            int j;

            char* iC = pNodeI->first_attribute()->value(); //aixo es el valor de i
            char* ip = pNodeI->first_attribute()->value() + 1;
            //auto a = iC++;
            //if(*ip<=1)
            if (*ip != NULL) {
                i = *ip - 48;
                i += 10;
            }
            else {

                i = *iC - 48;
            }
            //std::cout << ip << " ";
            //int* a = (int*)ip;
            //std::cout << *a << " ";

            //auto prueba = pNodeI->first_attribute()->value();
            /*int a = *i;
            int b = *i++;*/
            pattr = pNodeI->first_attribute();
            pattr++;
            //std::cout << i << "\n";
            char* jC = pattr->value(); //aixo es el valor de j
            char* jT = pattr->value() + 1;

            if (*jT != NULL) {
                j = *jT - 48;
                j += 10;
            }
            else {
                j = *jC - 48;
            }
            //std::cout << jT << " ";
            //std::cout << "\n";

            //j = *jC - 48;

            char* typeB = pNodeI->last_attribute()->value(); //aixo es el type de brick
            //int holder = *typeB;
            type = CharToBrick(*typeB);

            float destXP = 271 + (20 * j);
            float destYP = -5 + 40 * i;

            Vector2D<float>forPush;
            forPush.X = (float)destXP;
            forPush.Y = (float)destYP;
            //35.45
            //17.72
            bool powerUp;           
            int probabilityRandom = rand() % 100;
            if (probabilityRandom < probabilityPowerUp) {
                powerUp = true;
            }
            else {
                powerUp = false;
            }

            positions.push_back(forPush);
            _map[i][j] = *new Brick(_renderer, 90, destXP, destYP, 40, 20, 0, type, powerUp, timePowerup);

            // map[i][j].Render();
            ip = nullptr;
            delete ip;
        }

    }
}

void GameInfo::PowerUpsInformation()
{
    rapidxml::xml_document<> doc;
    std::ifstream file("resources/config.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);


    rapidxml::xml_node<>* pRoot = doc.first_node();
    rapidxml::xml_node<>* pNodee = pRoot->last_node();
    rapidxml::xml_node<>* pNodeII = pNodee->first_node();    

    std::stringstream auxiliar;

    char* probability = pNodeII->first_attribute()->value(); //aixo es el valor de probabilitat
    char* time = pNodeII->last_attribute()->value(); //aixo es el valor de time
    

    auxiliar << probability;
    auxiliar >> probabilityPowerUp;
    auxiliar.clear();
    auxiliar << time;
    auxiliar >> timePowerup;
    auxiliar.clear();

    

}
