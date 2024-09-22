#include <iostream>
#include <vector>
using namespace std;

const int BoardSize = 3;

void PrintBoard(const vector<vector<char>>& board) 
{
    cout<<endl;
    for (int i = 0; i < BoardSize; ++i) 
    {
        for (int j = 0; j < BoardSize; ++j) 
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
// Checking rows if a player has won.
bool rowWin(const vector<vector<char>>& board, char player)
{
    // Check rows and columns
    for (int i = 0; i < BoardSize; ++i) 
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    return false;

}

// Checking rows if a player has won.
bool colWin(const vector<vector<char>>& board, char player)
{
    for (int i = 0; i < BoardSize; ++i) 
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    return false;
}

bool diagonalWin(const vector<vector<char>>& board, char player)
{
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
        return true;

    return false;
    
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) 
{
    // Check diagonals
    if(rowWin(board,player) or colWin(board,player) or diagonalWin(board,player))
    {
        return true;
    }
    return false;    
}

// Function to check if the game ended in a draw
bool checkDraw(const vector<vector<char>>& board) 
{
    for (int i = 0; i < BoardSize; ++i) 
    {
        for (int j = 0; j < BoardSize; ++j) 
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function to make a move
bool makeMove(vector<vector<char>>& board, int row, int col, char player) 
{
    if (row >= 0 && row < BoardSize && col >= 0 && col < BoardSize && board[row][col] == ' ') 
    {
        board[row][col] = player;
        return true;
    }
    return false;
}

int main() 
{
    vector<vector<char>> board(BoardSize, vector<char>(BoardSize, ' '));
    char CurrentPlayerSymbol = 'X';

    cout << "Tic-Tac-Toe Game\n";
    PrintBoard(board);

    while (true) 
    {
        int row, col;
        cout << "Player " << CurrentPlayerSymbol << " turn, please enter row and column : ";
        cin >> row >> col;

        if (makeMove(board, row, col, CurrentPlayerSymbol)) 
        {
            PrintBoard(board);

            if (checkWin(board, CurrentPlayerSymbol)) 
            {
                cout << "Player " << CurrentPlayerSymbol << " wins!" << endl;
                break;
            }

            if (checkDraw(board)) 
            {
                cout << "It's a draw!" << endl;
                break;
            }

            CurrentPlayerSymbol = (CurrentPlayerSymbol == 'X') ? 'O' : 'X';
        } 
        else 
        {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}
