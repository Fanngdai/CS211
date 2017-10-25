// Dai, Fanng
// CSCI211
// eqivalent arrays
#include <iostream>
using namespace std;

// n is the size of the arrays
bool equivalent ( int a[ ], int b[ ], int n )
{
    for (int shift_amt = 0; shift_amt < n; shift_amt ++)
    {
        for (int j = 0; j < n; j ++)
        {
            // shift is on last shift AND first array doesn't equal second return
            if ( shift_amt == n-1 &&  a[j] != b[ (j + shift_amt) % n] ) return false;
            if ( a[j] != b[ (j + shift_amt) % n] ) break;
            // if all numbers are checked then return true
            if ( a[j] == b[ (j + shift_amt) % n] && j == n-1) return true;
        }   
    }   
}

int main() {
   int a1[5] = {1, 2, 3, 4, 5};
   int a2[5] = {3, 4, 5, 1, 2};
   cout << equivalent(a1, a2, 5) << endl; // true
   
   int b1[3] = {1, 2, 3};
   int b2[3] = {2, 3, 3};
   cout << equivalent(b1, b2, 3) << endl; // false
   
   int c1[4] = {2, 3, 4, 1};
   int c2[4] = {1, 4, 3, 2};
   cout << equivalent(c1, c2, 4) << endl; // false
   
   int d1[4] = {3, 2, 3, 1};
   int d2[4] = {3, 1, 3, 2};
   cout << equivalent(d1, d2, 4) << endl; // true
   
   int e1[5] = {1, 1, 1, 1, 2};
   int e2[5] = {1, 1, 1, 2, 1};
   cout << equivalent(e1, e2, 5) << endl; // true
   
   return 0;
}