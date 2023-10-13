#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Movie {
public:
    Movie(string title, string showtime, double price, int numSeats)
        : title(title), showtime(showtime), price(price), availableSeats(numSeats) {
        InitializeSeats();
    }

    void InitializeSeats() {
        seats.resize(3, vector<char>(3, 'O'));
    }

    void DisplaySeats() {
        cout << "Available Seats (O: Available, X: Booked):" << endl;
        for (const auto& row : seats) {
            for (char seat : row) {
                cout << seat << ' ';
            }
            cout << endl;
        }
    }

    bool IsSeatAvailable(int row, int col) {
        return seats[row - 1][col - 1] == 'O';
    }

    bool BookSeats(const vector<pair<int, int>>& selectedSeats) {
        for (const auto& seat : selectedSeats) {
            int row = seat.first - 1;
            int col = seat.second - 1;
            if (row >= 0 && row < 3 && col >= 0 && col < 3) {
                if (seats[row][col] == 'O') {
                    seats[row][col] = 'X';
                    availableSeats--;
                }
                else {
                    cout << "Seat " << seat.first << "-" << seat.second << " is already booked." << endl;
                    return false;
                }
            }
            else {
                cout << "Invalid seat selection." << endl;
                return false;
            }
        }
        return true;
    }

    double CalculateTotalCost(const vector<pair<int, int>>& selectedSeats) {
        return selectedSeats.size() * price;
    }

    int GetAvailableSeats() {
        return availableSeats;
    }

    string GetTitle() {
        return title;
    }

    string GetShowtime() {
        return showtime;
    }

private:
    string title;
    string showtime;
    double price;
    int availableSeats;
    vector<vector<char>> seats;
};

int main() {
    vector<Movie> movies = {
        Movie("Movie 1", "10:00 AM", 10.00, 9),
        Movie("Movie 2", "1:00 PM", 8.00, 9),
        Movie("Movie 3", "4:00 PM", 12.00, 9)
    };

    while (true) {
        cout << "Movie Listings:" << endl;
        for (int i = 0; i < movies.size(); i++) {
            cout << i + 1 << ". " << movies[i].GetTitle() << " (" << movies[i].GetShowtime() << ") - $"
                      << fixed << setprecision(2) << movies[i].CalculateTotalCost({}) << " (" << movies[i].GetAvailableSeats() << " seats available)" << endl;
        }

        int choice;
        cout << "Enter the movie number (1-" << movies.size() << ") or 0 to exit: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }
        else if (choice >= 1 && choice <= movies.size()) {
            Movie& selectedMovie = movies[choice - 1];
            selectedMovie.DisplaySeats();

            vector<pair<int, int>> selectedSeats;
            while (true) {
                int row, col;
                cout << "Enter the row number (1-3) and seat number (1-3) or 0 to finish: ";
                cin >> row;
                if (row == 0) {
                    break;
                }
                cin >> col;

                if (selectedMovie.IsSeatAvailable(row, col)) {
                    selectedSeats.push_back({row, col});
                }
                else {
                    cout << "Seat " << row << "-" << col << " is not available. Choose another seat." << endl;
                }
            }

            if (!selectedSeats.empty()) {
                double totalCost = selectedMovie.CalculateTotalCost(selectedSeats);
                cout << "Booking Summary for " << selectedMovie.GetTitle() << " (" << selectedMovie.GetShowtime() << "):" << endl;
                for (const auto& seat : selectedSeats) {
                    cout << "Seat " << seat.first << "-" << seat.second << endl;
                }
                cout << "Total cost: $" << fixed << setprecision(2) << totalCost << endl;

                char confirm;
                cout << "Confirm booking (y/n)? ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    if (selectedMovie.BookSeats(selectedSeats)) {
                        cout << "Booking confirmed. Enjoy the movie!" << endl;
                    }
                    else {
                        cout << "Booking failed. Please try again." << endl;
                    }
                }
                else {
                    cout << "Booking canceled. Returning to movie selection." << endl;
                }
            }
            else {
                cout << "No seats selected. Returning to movie selection." << endl;
            }
        }
        else {
            cout << "Invalid movie selection. Please choose a valid movie number." << endl;
        }
    }

    return 0;
}
