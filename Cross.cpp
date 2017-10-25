#include <iostream>
#include <cmath>
using namespace std;

bool okay (int q[], int c) {
    
    static int adj[8][5] = {
    {-1},                 // 0
    {0, -1},              // 1
    {0, 1, -1},           // 2
    {0, 2, -1},           // 3
    {1, 2, -1},           // 4
    {1, 2, 3, 4, -1},     // 5
    {2, 3, 5, -1},        // 6
    {4, 5, 6, -1}         // 7
    };                         

    for (int i = 0; i < c; i++)
    {
        if ( q[c] == q[i] ) return false;
    }

    for (int i = 0; adj[c][i] != -1; i++)
    {
        if ( abs ( q[c] - q[ adj [c][i] ] ) == 1) return false;
    }

   return true;
}

void print ( int q[ ] )
{
    static int counter = 0;
    cout << "Solution #" << ++counter << endl;
    cout << " "  << q[1]+1 << q[4]+1 << endl;
    cout << q[0]+1 << q[2]+1 << q[5]+1 << q[7]+1 << endl;
    cout << " "  << q[3]+1 << q[6]+1 << endl;  
    cout << endl;
}

void next(int q[ ], int c) {
   if (c == 8)
      print(q);
   else for (q[c] = 0; q[c] < 8; ++q[c])
      if (okay(q, c))
         next(q, c+1);
}

int main() {
   int q[8];
   next(q, 0);
   return 0;
}