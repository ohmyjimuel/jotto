#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

const int WORD_LENGTH = 5;
const int NOT_MATCHED = 0;
const int PARTIAL_MATCHED = 1;
const int MATCHED = 2;
const int NUMBER_OF_GUESSES = 6;

void toUpperCase(std::string &input)
{
    std::transform(First: input.begin(), Last: input.end(), Dest: input.begin(), Func: [](unsigned char c)
                    { return std::toupper(C:c); });
}

std::string getRandomWord()
{
    // TODO fetch random word from API (e.g. WordsAPI)
    return "ready";
}

bool isValidWord(std::string word)
{
    //TODO check word correctness from API (e.g. WordsAPI)
    return word.length() == WORD_LENGTH && word.find_first_not_of(Ptr:"ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
}

void markMatches(std::vector<std::vector<int>> &matches, int currentGuessIndex, std::string targetWord, std::string guessWord)
{
    for (int i = 0; i < guessWord.length(); i++)
    {
        matches[currentGuessIndex][i] = NOT_MATCHED;
    }

    for (int i = 0; i < guessWord.length(); i++)
    {
        for (int j = 0; j < targetWord.length(); j++)
        {
            if(guessword[i] == targetWord[j])
            {
                if (i == j)
                {
                    matches[currentGuessIndex][i] = MATCHED;
                    break;
                }
                else
                {
                matches[currentGuessIndex][i] = PARTIAL_MATCHED;
                }
            }   
        }
    }
}

bool isAllMatched(std::string targetWord, std::string guessWord)
{
    for (int i = 0; i < targetWord.length(); i++)
    {
        if(targetWord[i] != guessWord[i])
            return false;
    }

    return true;
}