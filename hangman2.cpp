#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

const int ARRAY_SIZE = 10;
const int MAX_LIVES = 5;

// Function to draw hangman based on the number of lives
void drawHangman(int lives) {
    std::cout << "\n";
    switch (lives) {
        case 4:
            std::cout << "   ___" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            break;
        case 3:
            std::cout << "   ___" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  |   O" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            break;
        case 2:
            std::cout << "   ___" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  |   O" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            break;
        case 1:
            std::cout << "   ___" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  |   O" << std::endl;
            std::cout << "  |  /|\\" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            break;
        case 0:
            std::cout << "   ___" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  |   O" << std::endl;
            std::cout << "  |  /|\\" << std::endl;
            std::cout << "  |  / \\" << std::endl;
            std::cout << "  |" << std::endl;
            std::cout << "  |" << std::endl;
            break;
        default:
            break;
    }
    std::cout << std::endl;
}

int main() {
    // Initialize the random number generator
    srand(time(0));

    // Define an array of words
    std::string nobodys[ARRAY_SIZE] = { "dave", "ian", "carol", "simon", "peter", "sandra", "alan", "steve", "elliot", "keith" };

    // Select a random word from the array
    std::string answer = nobodys[rand() % ARRAY_SIZE];

    std::vector<int> foundCharIndexes;
    int lives = MAX_LIVES;

    // Game loop
    while (foundCharIndexes.size() < answer.size() && lives > 0) {
        // Output hangman and the number of lives
        drawHangman(lives);

        // Print out the current set of letters
        for (int i = 0; i < answer.length(); ++i) {
            if (std::find(foundCharIndexes.begin(), foundCharIndexes.end(), i) != foundCharIndexes.end()) {
                std::cout << answer[i] << " ";
            } else {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;

        // Get the user's choice
        char userChoice = ' ';
        bool found = false;
        std::cout << "Choose a character..." << std::endl;
        std::cin >> userChoice;

        // Validate the user's input
        if (userChoice < 'a' || userChoice > 'z') {
            std::cout << "Please enter a lowercase letter." << std::endl;
            continue;
        }

        // Check if the user's choice is in the answer
        for (int i = 0; i < answer.length(); i++) {
            if (userChoice == answer[i]) {
                found = true;

                // Check if the character has already been guessed
                if (std::find(foundCharIndexes.begin(), foundCharIndexes.end(), i) == foundCharIndexes.end()) {
                    foundCharIndexes.push_back(i);
                } else {
                    std::cout << "You already guessed this character." << std::endl;
                }
            }
        }

        // Update lives if applicable
        if (!found) {
            lives--;
        }
    }

    // Output game conclusion
    drawHangman(lives); // Final hangman drawing
    if (lives > 0) {
        std::cout << "\nCongratulations, you found the word: " << answer << "!" << std::endl;
    } else {
        std::cout << "\nOh no, you ran out of lives. The word was: " << answer << "!" << std::endl;
    }

    return 0;
}
