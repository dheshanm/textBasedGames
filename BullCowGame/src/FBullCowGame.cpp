#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {	reset(); }

int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const {	return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameisWon; } // TODO implement function

void FBullCowGame::reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	myMaxTries = MAX_TRIES;
	myHiddenWord = HIDDEN_WORD;
	myCurrentTry = 0;
	bGameisWon = false;
	return;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString Guess) const {
	if(false) {		// Check in not an Isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {	// Check if all characters are in lowercase
		return EGuessStatus::Not_Lowercase;
	}
	else if(getHiddenWordLength() != Guess.length()) {	// Check if correct length
		return EGuessStatus::Wrong_Length;
	}
	return EGuessStatus::OK;	//TODO Make an Actual Error list
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
