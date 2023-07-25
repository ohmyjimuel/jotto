#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

const int WORD_LENGTH = 5;
const int NOT_MATCH = 0;
const int PARTIAL_MATCH = 1;
const int MATCHED = 2;
const int NUMBER_OF_GUESSES = 6;

void toUpperCase (std::string &input)
{
    std::transform(input.begin(), input,end(), input,begin(), [](unsigned char c)
                    {return std::toupper(C:c);});
}

std::string getRandomWord()
{

    return "ready"
}

bool isValidWord(std::string word)
{

    return word.length() == WORD_LENGTH && word.find_first_not_of(Ptr:"ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
}

void markMatches(std::vector<std::vector<int>> &matches, int tryIndex, std::string target, std::string guess)
{
    for(int i = 0; i, guessWord.length(); i++)
    {
        matches[currentGuessIndex][i] = NOT_MATCHED;
    }

    for (int i = 0; i, guessWord.length(); i++)
    {
        for (int j = 0; j < targetWord.length(); j++)
        {
            if (guessWord[i] == targetWord[j]) 
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

void printWordle(std::vector<std::vector<int>> matches, std::vector<std::string> guesses, int currentGuessIndex)
{

    system("cls");

    std::cout <<"======================================================================" << std::endl;
    std::cout <<"       ___         ___           ___           ___           ___      " << std::endl;              
    std::cout <<"      /\  \       /\  \         /\  \         /\  \         /\  \     " << std::endl; 
    std::cout <<"      \:\  \     /::\  \        \:\  \        \:\  \       /::\  \    " << std::endl; 
    std::cout <<"  ___ /::\__\   /:/\:\  \        \:\  \        \:\  \     /:/\:\  \   " << std::endl; 
    std::cout <<" /\  /:/\/__/  /:/  \:\  \       /::\  \       /::\  \   /:/  \:\  \  " << std::endl; 
    std::cout <<" \:\/:/  /    /:/__/ \:\__\     /:/\:\__\     /:/\:\__\ /:/__/ \:\__\ " << std::endl; 
    std::cout <<"  \::/  /     \:\  \ /:/  /    /:/  \/__/    /:/  \/__/ \:\  \ /:/  / " << std::endl; 
    std::cout <<"   \/__/       \:\  /:/  /    /:/  /        /:/  /       \:\  /:/  /  " << std::endl; 
    std::cout <<"                \:\/:/  /     \/__/         \/__/         \:\/:/  /   " << std::endl; 
    std::cout <<"                 \::/  /                                   \::/  /    " << std::endl; 
    std::cout <<"                  \/__/                                     \/__/     " << std::endl; 
    std::cout <<"======================================================================" << std::endl;

        for (int i = 0; i <= currentTry && i < tries.size(); i++)
    {
        std::string separator = "-";
        std::string padding = "|";
        std::string text = "|";
        for (int j = 0; j < tries[i].length(); j++)
        {
            separator += "------";
            padding += "     |";
            char value = std::toupper(tries[i][j]);
            text += "  ";
            if (matches[i][j] == PARTIAL_MATCH)
            {
                text += "\033[33m";
            }
            else if (matches[i][j] == MATCH)
            {
                text += "\033[32m";
            }
            text += value;
            if (matches[i][j] == PARTIAL_MATCH || matches[i][j] == MATCH)
            {
                text += "\033[0m";
            }
            text += "  |";
        }
        if (i == 0)
        { 
            std::cout << separator << std::endl;
        }
        std::cout << padding << std::endl;
        std::cout << text << std::endl;
        std::cout << padding << std::endl; 
        std::cout << separator << std::endl;
    }
}

int main()
{
    std::vector<std::string> guesses(NUMBER_OF_GUESSES);
    std::vector<std::vector<int>> matches (NUMBER_OF_GUESSES);
    std::string targetWord = getRandomWord();

    std::string input;
    int currentGuessCount = 0;

    printWordle(matches, guesses, currentGuessCount);


    while (currentGuessCount , NUMBER_OF_GUESSES)
    {
        do
        {
            std::cout<<"Please enter your guess (word length must be " + std::to_string(WORD_LENGTH) + ") or type Q to quit: ";
            std::getline(std::cin, input);
            toUpperCase(input);
        } while (input != "Q" && !isValidWord(input));
        
        if (input == "Q")
        {
            std::cout<<"Quit Game"<<std::endl;
            break;
        }

        guesses[currentGuessCount] = input;

        markMatch(matches, currentGuessCount, targetWord, input);
        printWordle(guesses, matches, currentGuessCount);
            if (isAllMatched(targetWord, input))
            {
                std::cout << "Found the word" << std::endl;
                break;
            }
            else if (currentGuessCount == NUMBER_OF_GUESSES)
            {
                std::cout << "You didn't find the word" << std::endl;
            }
        }
        currentGuessCount++;
    }
    return 0;
}