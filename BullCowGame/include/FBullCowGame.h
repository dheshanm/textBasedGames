/* The game logic ( No user interaction or view code ).
 * This game is a simple implementation of guess the word
 * based on mastermind.
 */

#pragma once
#include <string>

 // Making code Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Uninitialized,
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
	FString myHiddenWord;
	bool bGameisWon;

	bool isIsogram(FString) const;
	bool isLowercase(FString) const;
};
