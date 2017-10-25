#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) 
{
   for( int i = 0; i < c; i++)
   {
        if( q[i] == q[c] || c - i == abs ( q[c] - q[i] )) return false;  
   }
   return true;
}

// This function should return the number of solutions for the given board size.
int nqueens(int n) 
{
    int * q = new int [n]; 
    int col = 0, counter = 0;            // declaring arrar (row) and column & setting = to 0

    nextColumn:
    col++;                              // Go to next column
    if ( col == n ) goto print;           // If we went through the board, print
    q[col] = -1;                        // Start at row -1... Will change in nextRow
    
    nextRow:
    q[col]++;                            // Go to next row
    if ( q[col] == n ) goto backTrack;   // If entire row doesn't work, we go to last column

    for ( int i = 0; i < col; i++)      // Testing for rows & diagonals
    {
        if ( q[col] == q[i] ||  q[i] - q[col] == col - i || q[i] - q[col] == i - col) goto nextRow;    
    }
    
    goto nextColumn;                    // If everything is okay, we go to next column
    
    backTrack:
    col --;                             // Go back to previoud column
    if (col == -1 ) 
    {
        delete [ ] q;               // since we have this in a array, we don't need it...
        return counter;           // If we have done every choice, we quit
    }
    goto nextRow;                       // Or we continue the row
    
    print:
    ++counter;
    goto backTrack;
    
   // Dynamically declare an array of size n and initialize the first element to 0.
   // You don't need to print the solutions.  Just increment a counter each time you find a solution.
   // Reuse the code from your 1D 8 queens program to find the solutions (you may have to make changes).
   // Delete the array.
   // Return the number of solutions.
}

int main() {
   int n = 8;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << "\t solutions to the " << i << "\t queens problem.\n";
   return 0;
}