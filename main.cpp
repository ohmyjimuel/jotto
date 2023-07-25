#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <Windows.h>

const int WORD_LENGTH = 5;
const int NOT_MATCH = 0;
const int PARTIAL_MATCH = 1;
const int MATCH = 2;

void toUpperCase(std::string &input)
{
    std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c)
    { return std::toupper(c); });
}

std::string getRandomWord()
{
    // TODO fetch random word from API (e.g. WordsAPI)
    return "ready";
}

bool isValid(std::string word)
{
    // TODO check word correctness from API (e.g. WordsAPI)
    return word.length() == WORD_LENGTH && word.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
}

void markMatch(std::vector<std::vector<int>> &matches, int tryIndex, std::string target, std::string guess)
{
    for (int i = 0; i < guess.length(); i++)
    {
        matches[tryIndex][i] = NOT_MATCH;
    }
    for (int j = 0; j < guess.length(); j++)
    {
        for (int i = 0; i < target.length(); i++)
        {
            if (guess[j] == target[i])
            {
                if (i == j)
                {
                    matches[tryIndex][j] = MATCH;
                   break;
                }
                else
                {
                    matches[tryIndex][j] = PARTIAL_MATCH;
                }
            }
        }
    }
}

bool isAllMatch(std::string target, std::string guess)
{
    for (int i = 0; i < guess.length(); i++)
    {
        if (guess[i] != target[i])
            return false;
    }
    return true;
}

void printWordle(std::vector<std::string> tries, std::vector<std::vector<int>> matches, int currentTry)
{
    system("cls");
    std::cout << "=================================================================" << std::endl;
    std::cout << "|                                                               |" << std::endl;
    std::cout << "|   $$\\      $$\\                           $$\\ $$\\   |" << std::endl;
    std::cout << "|   $$ | $\\  $$ |                          $$ |$$ |             |" << std::endl;
    std::cout << "|   $$ |$$$\\ $$ | $$$$$$\\   $$$$$$\\   $$$$$$$ |$$ | $$$$$$\\     |" << std::endl;
    std::cout << "|   $$ $$ $$\\$$ |$$  __$$\\ $$  __$$\\ $$  __$$ |$$ |$$  __$$\\    |" << std::endl;
    std::cout << "|   $$$$  _$$$$ |$$ /  $$ |$$ |  \\__|$$ /  $$ |$$ |$$$$$$$$ |   |" << std::endl;
    std::cout << "|   $$$  / \\$$$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |$$   ____|   |" << std::endl;
    std::cout << "|   $$  /   \\$$ |\\$$$$$$  |$$ |      \\$$$$$$$ |$$ |\\$$$$$$$\\    |" << std::endl;
    std::cout << "|   \\__/     \\__| \\______/ \\__|       \\_______|\\__| \\_______|   |" << std::endl;
    std::cout << "|                                                               |" << std::endl;
    std::cout << "=================================================================" << std::endl;
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

int main(int, char **)
{
    int numberOfTries = 6;
    std::vector<std::string> tries(numberOfTries);
    std::vector<std::vector<int>> matches(numberOfTries, std::vector<int>(WORD_LENGTH));
    std::string targetWord = getRandomWord();
    toUpperCase(targetWord);
    std::string input;
    int currentTry = 0;
    while (currentTry < numberOfTries)
    {
        do
        {
            std::cout << "Please enter your guess (word length must be " + std::to_string(WORD_LENGTH) + ") or type Q to quit: ";
            std::getline(std::cin, input);
            toUpperCase(input);
        } while (input != "Q" && !isValid(input));
        if (input == "Q")
        {
            std::cout << "Quit game" << std::endl;
            break;
        }
        tries[currentTry] = input;
        currentTry++;
    }

    markMatch(matches, currentTry, targetWord, input);
    printWordle(tries, matches, currentTry);
    if (isAllMatch(targetWord, input))
    {
        std::cout << "Found the word" << std::endl;
    }
    else if (currentTry == numberOfTries)
    {
        std::cout << "You didn't find the word" << std::endl;
    }
    return 0;
}