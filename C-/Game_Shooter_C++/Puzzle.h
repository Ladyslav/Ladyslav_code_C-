#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Puzzle
{

private:
	std::string question; 
	std::vector<std::string> answers;
	int correctAnswers;

public:
	Puzzle(std::string fileName);
	virtual ~Puzzle();
	std::string getAsString();

	inline const int& getCorrectAns() const { return this->correctAnswers; } 

};

 

