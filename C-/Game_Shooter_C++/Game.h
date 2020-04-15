
#pragma once
#include "Functions.h"
#include "Character.h"
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();

	//operators 

	//Functions
	void mainMenu();
	void initGame();
	void createNewCharacter();
	void saveCharacters();
	void loadCharacters();

	//Accessors
	inline bool getPlaying() const { return  this->playing; }

	//Modifiers

private:
	int choice;
	bool playing;

	//Character related
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;
};