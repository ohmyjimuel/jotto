#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if the guessed word matches the target word
bool isMatch(const string target, const string guess) {
    if (target.length() != guess.length()) {
        return false;
    }

    for (size_t i = 0; i < target.length(); ++i) {
        if (target[i] != guess[i]) {
            return false;
        }
    }

    return true;
}

// Function to get the feedback for the guessed word
string getFeedback(const string target, const string guess) {
    string feedback;
    for (size_t i = 0; i < target.length(); ++i) {
        if (target[i] == guess[i]) {
            feedback += target[i];
        } else if (target.find(guess[i]) != string::npos) {
            feedback += "?";
        } else {
            feedback += "*";
        }
    }

    return feedback;
}

// Function to get a random word of the specified length
string getRandomWord(int length) {
    vector<string> words;
    
    // Add words of the specified length to the vector
    if (length == 3) {
        words = { "bat", "cat", "dog", "fan", "hat", "car" };
    } else if (length == 4) {
        words = { "frog", "jump", "cake", "love", "rock", "fire" };
    } else if (length == 5) {
        words = { "apple", "lemon", "happy", "world", "music", "beach" };
    }
    
    srand(static_cast<unsigned>(time(nullptr)));
    random_shuffle(words.begin(), words.end());
    return words[0];
}

int main() {
    cout<<"--------------------------------\n";
    cout<<"    J  OOO  TTTTTT TTTTTT  OOO  \n";
    cout<<"    J O   O   TT     TT   O   O \n";
    cout<<"    J O   O   TT     TT   O   O \n";
    cout<<"J   J O   O   TT     TT   O   O \n";
    cout<<" JJJ   OOO    TT     TT    OOO  \n";
    cout<<"--------------------------------\n";

    cout << "Welcome to Jotto!\n";
    cout << "How to Play:\n";
    cout << "In this game, you will try to guess a word with varying number of letters, and limited attempts, based on the difficulty level.\n";
    cout << "In solving for the word, you will encounter special characters, such as ? and *, the ? means that the letter used is correct, but placed in a wrong position, while the * means that the letter is not included in the word at all.\n";
    cout << "The game will end once you have guess the correct word, or you have used all your attempts, and yet failed to solve the word.\n";
    cout << "----------------------------------------------------\n";
    cout << "Choose the difficulty level:\n";
    cout << "1 - Easy (3-letter word, 8 attempts)\n";
    cout << "2 - Medium (4-letter word, 6 attempts)\n";
    cout << "3 - Hard (5-letter word, 4 attempts)\n";
    cout << "Enter the difficulty: ";
    cout << "Enter the difficulty: ";

    int difficulty;
    cin >> difficulty;

    cout << "----------------------------------------------------\n";

    int wordLength;
    int attemptsLeft;

    switch (difficulty) {
        case 1: {
            wordLength = 3;
            attemptsLeft = 8;
            break;
        } case 2: {
            wordLength = 4;
            attemptsLeft = 6;
            break;
        } case 3: {
            wordLength = 5;
            attemptsLeft = 4;
            break;
        } default: {
            cout << "Invalid difficulty level. Please choose between 1, 2, or 3.\n";
            exit(EXIT_FAILURE);
        }
    }

    // Get the random word of the specified length for the player to guess
    string targetWord = getRandomWord(wordLength);
    
    // Main game loop
    for (int ctr = 1; ctr <= attemptsLeft; ctr++) {
        string guess;
        cout << "Enter your guess (attempt " << ctr << "): ";
        cin >> guess;

        // Convert the guess to lowercase
        transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

        if (isMatch(targetWord, guess)) {
            cout << "Congratulations! You guessed the word: " << targetWord << endl;
            break;
        } else {
            string feedback = getFeedback(targetWord, guess);
            cout << "Feedback: " << feedback << endl;
        }

        if (ctr == attemptsLeft)
            cout << "Sorry, you have used all your attempts. The word was: " << targetWord << std::endl;
    }
    
    return 0;
}
