/* This is the console executable that uses and implements the FBullCowame class
 * This acts as the view in a MCV pattern and is responsible for all the user
 * Interraction. For game logic see FBullCowGame class.
 */

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame BCGame;		//Instantiate a Game instance

void printIntro() {
	constexpr int32 WORD_LENGTH = 9;

	// Game Introduction
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of ?" << std::endl;
	std::cout << std::endl;

	return;
}

FText getGuess() {
	int32 currentTry = BCGame.getCurrentTry();
	//Get input from the user
	FText Guess = "";
	std::cout << "Try " << currentTry << ". Enter your Guess	:";
	getline(std::cin, Guess);

	return Guess;
}

void playGame() {
	BCGame.reset();
	int32 maxTries = BCGame.getMaxTries();
	
	//loop for number of turns
	// TODO change from FOR to WHILE loop
	for (int32 i = 0; i < maxTries; i++) {
		FText Guess = getGuess();		// TODO check if guess is valid

		// Submit valid guess to game
		FBullCowCount BullCowCount = BCGame.submitGuess(Guess);	
		// print number of Bulls and Games
		std::cout << "Bulls  = " << BullCowCount.Bulls;
		std::cout << ". Cows  = " << BullCowCount.Cows << std::endl;
	}

	// TODO Add a Game Summary
}

bool AskToPlay() {
	bool control = false;
	std::cout << "Do you want to Play again		?";
	FText response = "";
	getline(std::cin,response);

	if(response[0]=='y' || response[0]=='Y' || response[0]=='1') {
		control = true;
	}
	return control;
}

//Application Entry point
int main() {

	do {
		printIntro();
		playGame();
	} while (AskToPlay());
	return 0;		//Exit Application
}
