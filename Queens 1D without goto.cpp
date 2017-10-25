// Dai Fanng
// 8 Queens 1D no goto assignment

#include <iostream>
using namespace std;

bool okay( int q[ ], int col)
{
    for ( int i = 0; i < col; i++)
        {
            if ( q[col] == q[i] ||  abs (q[i] - q[col]) == col - i ) return false;
        }
        return true;
}

int main ( ) {
 
    int q[8] = { }, col = 0, counter = 0;
    
    while ( col != -1) 
    {
        col++;
        if ( col == 8 ) 
        {
            cout << "Solution # " << ++counter << ":\t";
            for ( int i = 0; i < 8; i++)
            {
                cout << q[i] ;
            }
            cout << endl;
            col --;
        }
    
        else q[col] = -1;
    
        while (col != -1)
        {
            q[col]++;
            while ( q[col] == 8 ) 
            {
                col --;
                q[col]++;        
            }
            if (okay (q , col )) break;
        }
    }
    return 0;
}