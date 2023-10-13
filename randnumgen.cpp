#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Generate a random number between 1 and 100
    int random_number = (rand() % 100) + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;

    while (true) {
        cout << "Guess the number (between 1 and 100): ";
        cin >> guess;
        attempts++;

        if (guess < random_number) {
            cout << "Too low! Try again." << endl;
        } else if (guess > random_number) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number " << random_number << " in " << attempts << " attempts!" << endl;
            break;
        }
    }

    cout << "Thank you for playing!" << endl;

    return 0;
}