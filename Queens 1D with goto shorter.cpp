#include <iostream>
using namespace std;

int main ( ) {
 
    int q[8] = { }, col = 0, counter = 0;            // declaring arrar (row) and column & setting = to 0

    nextColumn:
    col++;                              // Go to next column
    if ( col == 8 ) goto print;           // If we went through the board, print
    q[col] = -1;                        // Start at row -1... Will change in nextRow
    
    nextRow:
    q[col]++;                            // Go to next row
    if ( q[col] == 8 ) goto backTrack;   // If entire row doesn't work, we go to last column

    for ( int i = 0; i < col; i++)      // Testing for rows & diagonals
    {
        if ( q[col] == q[i] ||  q[i] - q[col] == col - i || q[i] - q[col] == i - col) goto nextRow;    
    }
    
    goto nextColumn;                    // If everything is okay, we go to next column
    
    backTrack:
    col --;                             // Go back to previoud column
    if (col == -1 ) return 0;           // If we have done every choice, we quit
    goto nextRow;                       // Or we continue the row
    
    print:
    cout << "Solution # " << ++counter << ":\t";
    for ( int i = 0; i < 8; i++)        // Print the solution we obtained
    {
        cout << q[i] ;
    }
    cout << endl;
    goto backTrack;
}