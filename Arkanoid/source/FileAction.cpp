#include "FileAction.h"

extern int winnerPoints;
std::map<int, std::string>gameRanking;


FileAction::FileAction(const std::string fileName)
{
	std::ifstream myFile;
	myFile.open(fileName, std::ios::in | std::ios::binary);

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
		gameRanking.insert(std::make_pair(position, content));
		content.clear();
	}
	//std::cout << winnerPoints;
	myFile.close();

    //std::remove("resources/Ranking.bin");
    //std::ofstream myFile;
    //myFile.open(fileName, std::ios::out | std::ios::binary);

    //std::stringstream empty;
    //std::stringstream information, information1, information2, information3, information4, information5, information6, information7, information8, information9;
    //size_t len, len1, len2, len3, len4, len5, len6, len7, len8, len9;
    //int position = 1, position1 = 2, position2 = 3, position3 = 4, position4 = 5, position5 = 6, position6 = 7, position7 = 8, position8 = 9, position9 = 10;

    //information << "Raul";
    //len = information.str().size();
    //for (int i = 0; i < 20 - len;i++) {
    //    information << ' ';
    //}
    //information << 300;
    //len = information.str().size();

    //myFile.write(reinterpret_cast<char*>(&position), sizeof(int));//se guarda posicion
    //myFile.write(reinterpret_cast<char*>(&len), sizeof(size_t)); //se guarda el size    
    //myFile.write(information.str().c_str(), information.str().size());// se guarda el string

    //information1 << "Juan";
    //len1 = information1.str().size();
    //for (int i = 0; i < 20 - len1;i++) {
    //    information1 << ' ';
    //}
    //information1 << 290;
    //len1 = information1.str().size();

    //myFile.write(reinterpret_cast<char*>(&position1), sizeof(int));//se guarda posicion
    //myFile.write(reinterpret_cast<char*>(&len1), sizeof(size_t)); //se guarda el size    
    //myFile.write(information1.str().c_str(), information1.str().size());// se guarda el string

    //information2 << "Cristian";
    //len2 = information2.str().size();
    //for (int i = 0; i < 20 - len2;i++) {
    //    information2 << ' ';
    //}
    //information2 << 280;
    //len2 = information2.str().size();

    //myFile.write(reinterpret_cast<char*>(&position2), sizeof(int));//se guarda posicion
    //myFile.write(reinterpret_cast<char*>(&len2), sizeof(size_t)); //se guarda el size    
    //myFile.write(information2.str().c_str(), information2.str().size());// se guarda el string

    //information3 << "Pol";
    //len3 = information3.str().size();
    //for (int i = 0; i < 20 - len3;i++) {
    //    information3 << ' ';
    //}
    //information3 << 270;
    //len3 = information3.str().size();

    //myFile.write(reinterpret_cast<char*>(&position3), sizeof(int));//se guarda posicion
    //myFile.write(reinterpret_cast<char*>(&len3), sizeof(size_t)); //se guarda el size    
    //myFile.write(information3.str().c_str(), information3.str().size());// se guarda el string

    //information4 << "Uri";
    //len4 = information4.str().size();
    //for (int i = 0; i < 20 - len4;i++) {
    //    information4 << ' ';
    //}
    //information4 << 260;
    //len4 = information4.str().size();

    //myFile.write(reinterpret_cast<char*>(&position4), sizeof(int));//se guarda posicion
    //myFile.write(reinterpret_cast<char*>(&len4), sizeof(size_t)); //se guarda el size    
    //myFile.write(information4.str().c_str(), information4.str().size());// se guarda el string

    //information5 << "Biel";
    //len5 = information5.str().size();
    //for (int i = 0; i < 20 - len5;i++) {
    //    information5 << ' ';
    //}
    //information5 << 250;
    //len5 = information5.str().size();

    //myFile.write(reinterpret_cast<char*>(&position5), sizeof(int));//se guarda posicion
    //myFile.write(reinterpret_cast<char*>(&len5), sizeof(size_t)); //se guarda el size    
    //myFile.write(information5.str().c_str(), information5.str().size());// se guarda el string

    //information6 << "Paula";
    //len6 = information6.str().size();
    //for (int i = 0; i < 20 - len6;i++) {
    //    information6 << ' ';
    //}
    //information6 << 240;
    //len6 = information6.str().size();

    //myFile.write(reinterpret_cast<char*>(&position6), sizeof(int));//se guarda posicion
    //myFile.write(reinterpret_cast<char*>(&len6), sizeof(size_t)); //se guarda el size    
    //myFile.write(information6.str().c_str(), information6.str().size());// se guarda el string

    //information7 << "Maria";
    //len7 = information7.str().size();
    //for (int i = 0; i < 20 - len7;i++) {
    //    information7 << ' ';
    //}
    //information7 << 230;
    //len7 = information7.str().size();

    //myFile.write(reinterpret_cast<char*>(&position7), sizeof(int));//se guarda posicion
    //myFile.write(reinterpret_cast<char*>(&len7), sizeof(size_t)); //se guarda el size    
    //myFile.write(information7.str().c_str(), information7.str().size());// se guarda el string

    //information8 << "Jofe";
    //len8 = information8.str().size();
    //for (int i = 0; i < 20 - len8;i++) {
    //    information8 << ' ';
    //}
    //information8 << 220;
    //len8 = information8.str().size();

    //myFile.write(reinterpret_cast<char*>(&position8), sizeof(int));//se guarda posicion
    //myFile.write(reinterpret_cast<char*>(&len8), sizeof(size_t)); //se guarda el size    
    //myFile.write(information8.str().c_str(), information8.str().size());// se guarda el string

    //information9 << "Albert";
    //len9 = information9.str().size();
    //for (int i = 0; i < 20 - len9;i++) {
    //    information9 << ' ';
    //}
    //information9 << 210;
    //len9 = information9.str().size();

    //myFile.write(reinterpret_cast<char*>(&position9), sizeof(int));//se guarda posicion
    //myFile.write(reinterpret_cast<char*>(&len9), sizeof(size_t)); //se guarda el size    
    //myFile.write(information9.str().c_str(), information9.str().size());// se guarda el string

    //myFile.close();

}
