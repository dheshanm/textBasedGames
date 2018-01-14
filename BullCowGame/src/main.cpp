/* This is the console executable that uses and implements the FBullCowame class
 * This acts as the view in a MCV pattern and is responsible for all the user
 * Interraction. For game logic see FBullCowGame class.
 */
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Making code Unreal friendly
using FText = std::string;
using int32 = int;

// Function prototypes.
void printIntro();
FText getValidGuess();
void playGame();
bool AskToPlay();
void printGameSummary();


FBullCowGame BCGame;		// Instantiate a Game instance [Instance is re-used accross plays].

// Application Entry point.
int main() {

	do {
		printIntro();
		playGame();
	} while (AskToPlay());
	return 0;		//Exit Application.
}

void printIntro() {
	std::cout << "\nWelcome to Bulls and Cows, a fun word game\n" << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.getHiddenWordLength() << " letter isogram I'm thinking of ?" << std::endl;
	std::cout << std::endl;

	return;
}

// Plays an instance of the game to completion.
void playGame() {
	BCGame.reset();
	int32 maxTries = BCGame.getMaxTries();
	
	//loop untill game is NOT won or there are tries left
	while ( !BCGame.isGameWon() && BCGame.getCurrentTry() <= maxTries) {
		FText Guess = getValidGuess();

		// Submit valid guess to game
		FBullCowCount BullCowCount = BCGame.submitValidGuess(Guess);	
		
		std::cout << "Bulls  = " << BullCowCount.Bulls;
		std::cout << ". Cows  = " << BullCowCount.Cows << std::endl << std::endl;
	}
	printGameSummary();
}

// loop continually until user enters a valid guess
FText getValidGuess() {
	// ReSharper disable once CppInitializedValueIsAlwaysRewritten
	EGuessStatus status = EGuessStatus::Uninitialized;
	FText Guess = "";

	do {
		//Get input from the user
		int32 currentTry = BCGame.getCurrentTry();
		std::cout << "Try " << currentTry << " of " << BCGame.getMaxTries()  << ". Enter your Guess	:";
		getline(std::cin, Guess);

		status = BCGame.checkGuessValidity(Guess);
		switch (status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "ERR_WRONGLENGTH: Please Enter a " << BCGame.getHiddenWordLength() << " letter guess." << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "ERR_NOTISOGRAM: Please Enter a word wothout repeating letter." << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "ERR_CASEMISMATCH: Please input only lowercase letters." << std::endl;
			break;
		case EGuessStatus::Uninitialized:
		case EGuessStatus::OK:
		default:
			// Assuming Guess is valid and exiting loop
			break;
		}
		if (status != EGuessStatus::OK) {
			std::cout << std::endl;
		}
	} while (status != EGuessStatus::OK);	// Keep looping until valid input is obtained.
	return Guess;
}


void printGameSummary() {
	if (BCGame.isGameWon()) {
		std::cout << "\tWell Done - You Win !!!" << std::endl;
	}
	else {
		std::cout << "\tBetter Luck Next Time..." << std::endl;
	}
}

bool AskToPlay() {
	bool control = false;
	std::cout << "Do you want to continue playing [SAME hidden word]  ? ";
	FText response = "";
	getline(std::cin,response);

	if(response[0]=='y' || response[0]=='Y' || response[0]=='1') {
		control = true;
	}
	return control;
}
