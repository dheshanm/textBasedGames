#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// Contains Bulls and Cow count.
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame{
public:
	FBullCowGame();	//constructor

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;
	bool isGameWon() const;
	bool checkGuessValidity(FString) const;

	void reset();
	FBullCowCount submitGuess(FString);	// Count Bulls and Cows and increase # of tries

private:
	// Initialized in constructor
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
};
