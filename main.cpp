#include <iostream>
#include <string>
using namespace std;

int main() {
    //James Welcome (ASCII ART)

    //Giuliani Instructions of the game

    //Shanley Enter the player's name, adventure message, winner message, tie message

    //Meg While loop if u want to play again

    // Variables to store player names
    string player1, player2;

    // Input name of the players
    cout << "Enter name of Player 1 (X): ";
    cin >> player1;
    cout << "Enter name of Player 2 (O): ";
    cin >> player2;

    // Good luck message before the game starts
    cout << endl << "Good luck, " << player1 << " and " << player2 << "!" << endl << endl;

    bool playAgain = true;

    while (playAgain) {
    cout << endl << endl;
        char board[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };

        const char playerX = 'X';
        const char playerO = 'O';
        char currentPlayer = playerX;
        int row = -1;
        int column = -1;
        char winner = ' ';

        for (int i = 0; i < 9; i++) {
            // Print game board
            cout << "   |   |   " << endl;
            cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
            cout << "___|___|___" << endl;
            cout << "   |   |   " << endl;
            cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
            cout << "___|___|___" << endl;
            cout << "   |   |   " << endl;
            cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
            cout << "   |   |   " << endl;

            if (winner != ' ') {
                break;
            }

            // Get player input
            cout << "Current Player is " << currentPlayer << " (" << (currentPlayer == playerX ? player1 : player2) << ")" << endl;
            while (true) {
                cout << "Enter 0-2 for row and column: ";
                cin >> row >> column;
                if (row < 0 || row > 2 || column < 0 || column > 2) {
                    cout << "Invalid input, try again." << endl;
                }
                else if (board[row][column] != ' ') {
                    cout << "Tile is full, try again." << endl;
                }
                else {
                    break;
                }
                // Reset values
                row = -1;
                column = -1;
                cin.clear(); // Clear error flags
                cin.ignore(10000, '\n'); // Discard values
            }

            board[row][column] = currentPlayer;
            currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

            // Check winners
            // Rows - horizontal
            for (int row = 0; row < 3; row++) {
                if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                    winner = board[row][0];
                    break;
                }
            }

            // Columns - vertical
            for (int column = 0; column < 3; column++) {
                if (board[0][column] != ' ' && board[0][column] == board[1][column] && board[1][column] == board[2][column]) {
                    winner = board[0][column];
                    break;
                }
            }

            // Diagonal
            if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                winner = board[0][0];
            }
            else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                winner = board[0][2];
            }
        }

        // Game result
        if (winner != ' ') {
            cout << endl <<"Player " << winner << " (" << (winner == playerX ? player1 : player2) << ") is the winner!" << endl;
        }
        else {
            cout << endl << "It's a tie! Well played, " << player1 << " and " << player2 << "!" << endl;
        }

        // Ask if they want to play again
        char playAgainChoice;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgainChoice;
        if (playAgainChoice != 'y' && playAgainChoice != 'Y') {
            playAgain = false;
        }
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
