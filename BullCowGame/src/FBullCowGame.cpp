#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {	reset(); }

int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const {	return int32(); }
bool FBullCowGame::isGameWon() const {}

void FBullCowGame::reset() {
	constexpr int32 MAX_TRIES = 8;
	myMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	myHiddenWord = HIDDEN_WORD;

	myCurrentTry = 0;
	return;
}

bool FBullCowGame::checkGuessValidity(FString) const { }

// Receives VALID guess, increments try #
FBullCowCount FBullCowGame::submitGuess(FString Guess) {
	// increment try #
	myCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	int32 hiddenWordLength = myHiddenWord.length();
	for(int32 HWChar =0; HWChar<hiddenWordLength; HWChar++) {
		for (int32 GChar = 0; GChar < hiddenWordLength; GChar++) {
			if(Guess[GChar] == myHiddenWord[HWChar]) {
				if(HWChar == GChar) { BullCowCount.Bulls++;	}
				else { BullCowCount.Cows++;   }
			}
		}
		
	}

	return BullCowCount;
}
