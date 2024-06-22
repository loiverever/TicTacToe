#include <iostream>
#include <string>
using namespace std;

int main() {
    //Contributions:
    //James Welcome (ASCII ART)

    //Giuliani Instructions of the game

    //Shanley Enter the player's name, adventure message, winner message, tie message

    //Meg While loop

    //Kate Score Tracking



    //Giuliani Instructions of the game
    cout << "Instructions:" << endl << endl;
    cout << "The game is played on a 3x3 grid." << endl;
    cout << "Player 1 is 'X' and Player 2 is 'O'." << endl;
    cout << "Players take turns placing their marks ('X' or 'O') in empty squares." << endl;
    cout << "Enter the row and column numbers (0, 1, or 2) separated by a space to place your mark." << endl;
    cout << "Rows and columns are numbered from 0 to 2, from top to bottom and left to right." << endl;
    cout << "For example, to place your mark in the top-left corner, enter '0 0'." << endl;
    cout << "Ensure your inputs are valid numbers between 0 and 2." << endl;
    cout << "The first player to get 3 of their marks in a row (horizontally, vertically, or diagonally) wins." << endl;
    cout << "If all 9 squares are full and no player has 3 in a row, the game is a tie." << endl << endl;




    //store players score
    int scorePlayer1 = 0, scorePlayer2 = 0;


    //Shanley Enter the player's name, adventure message, winner message, tie message
    // Variables to store player names
    string player1, player2;



    // Input name of the players
    cout << "Enter name of Player 1 (X): ";
    cin >> player1;
    cout << "Enter name of Player 2 (O): ";
    cin >> player2;

    // Good luck message before the game starts
    cout << endl << "Good luck, " << player1 << " and " << player2 << "!" << endl << endl;


    //Meg While Loop
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
                cout << endl << endl;
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

            //Kate Score Tracking
            // If there is a winner, update scores
            if (winner == playerX) {
                scorePlayer1++;
            } else if (winner == playerO) {
                scorePlayer2++;
            }
        }

        // Game result
        if (winner != ' ') {
            cout << endl <<"Player " << winner << " (" << (winner == playerX ? player1 : player2) << ") is the winner!" << endl;
            cout << endl;
        }
        else {
            cout << endl << "It's a tie! Well played, " << player1 << " and " << player2 << "!" << endl;
            cout << endl;
        }

        // Display scores
        cout << "Scores:" << endl;
        cout << player1 << ": " << scorePlayer1 << endl;
        cout << player2 << ": " << scorePlayer2 << endl;
        cout << endl;

        // Ask if they want to play again
        char playAgainChoice;
        cout << "Do you want to play again? (y/n): ";

        cin >> playAgainChoice;
        if (playAgainChoice != 'y' && playAgainChoice != 'Y') {
            playAgain = false;
        }
        cout << endl;
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
