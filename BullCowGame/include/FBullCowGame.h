#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// Contains Bulls and Cow count.
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid,
	OK,
	Wrong_Length,
	Not_Isogram,
	Not_Lowercase
};

class FBullCowGame{
public:
	FBullCowGame();	//constructor

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;
	EGuessStatus checkGuessValidity(FString) const;
	bool isGameWon() const;

	void reset();
	FBullCowCount submitValidGuess(FString);	// Count Bulls and Cows and increase # of tries

private:
	// Initialized in constructor
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
	bool bGameisWon;
};
