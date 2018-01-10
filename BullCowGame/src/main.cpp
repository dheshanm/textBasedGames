#include <iostream>
#include <string>

void printIntro() {
	constexpr int WORD_LENGTH = 9;

	// Game Introduction
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of ?" << std::endl;
	std::cout << std::endl;

	return;
}

std::string getGuess() {
	//Get input from the user
	std::string Guess = "";
	std::cout << "Enter your Guess	:";
	getline(std::cin, Guess);

	return Guess;
}

void playGame() {
	constexpr int NUMBER_OF_TURNS = 5;

	//loop for number of turns
	for (int i = 0; i < NUMBER_OF_TURNS; i++) {
		std::string Guess = getGuess();
		std::cout << "Your Guess was	:" << Guess << std::endl;
		std::cout << std::endl;
	}
}

//Application Entry point
int main() {

	printIntro();
	playGame();
	return 0;		//Exit Application
}
