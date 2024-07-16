#include <iostream>
#include <vector>

using namespace std;

class TicTacToe
{
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe()
    {
        // Initialize the game board
        board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        currentPlayer = 'X';
    }

    void displayBoard()
    {
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "-----------" << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "-----------" << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    }

    bool checkWin()
    {
        // Check rows
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            {
                return true;
            }
        }
        // Check columns
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        {
            return true;
        }
        return false;
    }

    bool checkDraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                {
                    return false;
                }
            }
        }
        return true;
    }

    char switchPlayer()
    {
        return currentPlayer == 'X' ? 'O' : 'X';
    }

    void play()
    {
        int move;

        while (true)
        {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            // Update the game board
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin())
            {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check if the game is a draw
            if (checkDraw())
            {
                displayBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players
            currentPlayer = switchPlayer();
        }

        // Ask if the players want to play again
        cout << "Do you want to play again? (y/n): ";
        char response;
        cin >> response;
        if (response == 'y')
        {
            // Reset the game board
            board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
            play();
        }
    }
};

int main()
{
    TicTacToe game;
    game.play();

    return 0;
}