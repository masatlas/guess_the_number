#include <iostream>
#include <ctime>   // For generating random numbers based on time
#include <cstdlib> // For random number generation

using namespace std;

int main() {
    const int minNumber = 1;
    const int maxNumber = 100;
    int secretNumber, guess;
    bool isGuessed = false;

    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate the secret number
    secretNumber = rand() % (maxNumber - minNumber + 1) + minNumber;

    cout << "Welcome to the Guess the Number game!\n";
    cout << "Try to guess a number between " << minNumber << " and " << maxNumber << ".\n";

    while (!isGuessed) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            if (guess < secretNumber) {
                cout << "Too low! Try again.\n";
            } else if (guess > secretNumber) {
                cout << "Too high! Try again.\n";
            } else {
                cout << "Congratulations! You guessed the correct number: " << secretNumber << endl;
                isGuessed = true;
            }
        }
    }

    return 0;
}
