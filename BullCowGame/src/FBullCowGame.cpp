#pragma once

#include "FBullCowGame.h"
#include <map>

// Making code Unreal friendly
#define TMap std::map
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {	reset(); }	// Default constructor

int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const {	return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameisWon; } 

int32 FBullCowGame::getMaxTries() const {
	std::map<int32, int32> wordLengthToMaxTries { {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return wordLengthToMaxTries[getHiddenWordLength()];
}

void FBullCowGame::reset() {
	const FString HIDDEN_WORD = "planet";	// This MUST be an Isogram

	myHiddenWord = HIDDEN_WORD;
	myCurrentTry = 0;
	bGameisWon = false;
	return;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString Guess) const {
	if(!isIsogram(Guess)) {		// Check in not an Isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (!isLowercase(Guess)) {	// Check if all characters are in lowercase
		return EGuessStatus::Not_Lowercase;
	}
	else if(getHiddenWordLength() != Guess.length()) {	// Check if correct length
		return EGuessStatus::Wrong_Length;
	}
	return EGuessStatus::OK;
}

// Receives VALID guess, increments try #
FBullCowCount FBullCowGame::submitValidGuess(FString Guess) {
	myCurrentTry++;
	int32 WordLength = myHiddenWord.length();	// Assuming same length as guess
	FBullCowCount BullCowCount;

	for(int32 HWChar =0; HWChar<WordLength; HWChar++) {
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			if(Guess[GChar] == myHiddenWord[HWChar]) {
				if(HWChar == GChar) { BullCowCount.Bulls++;	}
				else { BullCowCount.Cows++;   }
			}
		}
		
	}
	if (BullCowCount.Bulls == WordLength) { bGameisWon = true; }

	return BullCowCount;
}

bool FBullCowGame::isIsogram(FString word) const {
	if (word.length() < 2) { return true; }

	TMap <char, bool> letterSeen;

	for (auto letter : word) {
		if (letterSeen[letter]) { return false; }
		else { letterSeen[letter] = true; }
	}
	return true;	// For cases where '\0' is entered
}

bool FBullCowGame::isLowercase(FString word) const {
	for( auto letter : word) {
		if (!islower(letter)) {
			return false;
		}
	}
	return true;
}
