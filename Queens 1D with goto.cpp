// Dai Fanng
// 8 Queens 1D assignment

#include <iostream>
using namespace std;

bool testRow( int board[ ][8], int row, int column)
{
    for ( int i = 0; i < column; i++ )
    {
        if ( board[row][i] == 1 ) return true;
    }
    return false;
}

bool testDiagonalUpLeft( int board[ ][8], int row, int column)
{
    for ( int i = 0; (row - i) >= 0 && (column - i) >= 0; i++)
    {
        if ( board[row - i][column - i] == 1 ) return true;
    }
    return false;
}

bool testDiagonalDownLeft( int board[ ][8], int row, int column)
{
    for ( int i = 0; (row + i) <= 7 && (column - i) >= 0; i++)
    {
        if ( board[row + i][column - i] == 1 ) return true;
    }
    return false;
}

int main()
{
    // declare an 2d array, set equal to zero
    int board[8][8] = { };
    int printBoard[8];
    // declare row and column. Set equal to neg one
    int row, column = 0;
    int counter = 1;

    // Sets the most left and most up corner equal to 1
    board[0][0] = 1;

    
    NextColumn:
    column ++;
    if ( column == 8 ) goto print;
    row = -1;
    
    NextRow:
    row ++;
    
    if ( row == 8 ) goto backTrack;
    
    if (testRow (board, row, column)) goto NextRow;
    if (testDiagonalUpLeft (board, row, column)) goto NextRow;
    if (testDiagonalDownLeft (board, row, column)) goto NextRow;

    board[row][column]=1;
    printBoard[column] = row;
    goto NextColumn;
    
    backTrack:
    column --;
    if ( column == -1 ) return 0;
    row = 0;
    while ( board[row][column] != 1 ) row ++;
    board [row][column] = 0;
    goto NextRow;
    
    print:
    cout << "Solution #" << counter++ <<":\t";
    
    for (int c = 0; c <= 7; c++)
    {
        for(int r = 0; r <= 7; r++)
        {
            if ( board[c][r] != 0 )
            {
                cout << printBoard[c];
            }
        }
    }
    cout << endl;
    
    goto backTrack;
    
}