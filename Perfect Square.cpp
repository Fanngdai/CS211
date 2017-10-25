// Dai, Fanng
// CSCI211
// Perfect square
#include <iostream>
using namespace std;

int main ( ) 
{   
    // From 0 to limit, find value whose last two digits are both odd and can be squared
    int limit = 100;
    
    for ( int square = 0; square <= limit ; square++ )
    {
        int number;
        number = square * square;
        
        // if the answer we have found has odd for last two digits tell user and end program
        if ( number % 2 != 0 && (number / 10) % 2 != 0)
        { 
            cout << "The square of " << number << " is " << square;
            return 0;
        }
    }
    
    cout << "From 0 to " << limit;
    cout <<  " there is no value whose last two digits are both odd and perfect squares." ;
    
    return 0;
}