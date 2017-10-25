#include <iostream>
using namespace std;

// w[ m ] = current woman we working on
// m = current man we working on
bool okay( int w[ ], int m)
{
    static int mp[3][3] = { {0,2,1},  // Man#0's preferences
                            {0,2,1},  // Man#1's preferences
                            {1,2,0}}; // Man#2's preferences

    static int wp[3][3] = { {2,1,0},  // Woman#0's preferences
                            {0,1,2},  // Woman#1's preferences
                            {2,0,1}}; // Woman#2's preferences
   
   // g = guy being compared to
    for ( int g = 0; g < m; g++)
    {
        // paring one per person
        if ( w[ m ] == w[ g ] ) return false;
        
        // guy likes woman more than wife and
        // woman likes other guy more than husband
        if ( mp[g][w[g]] > mp[g][w[m]] && wp[w[m]][m] > wp[w[m]][g] ) return false;
        
        // woman likes man more than husband and
        // man likes woman more than wife
        if ( wp[w[m]][g] < wp[w[m]][m] && mp[m][w[g]] < mp[m][w[m]] ) return false;
    }
    
    return true;
}

void print(int q[]) 
{
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
   for (int i = 0; i < 3; ++i)
      cout << i << "\t" << q[i] << "\n";
   cout << "\n";
}

int main ( ) {
 
    int q[3] = { }, col = 0;
    
    while ( col != -1) 
    {
        col++;
        if ( col == 3 ) 
        {
            print(q);
            col --;
        }
    
        else q[col] = -1;
    
        while (col != -1)
        {
            q[col]++;
            while ( q[col] == 3 ) 
            {
                col --;
                q[col]++;        
            }
            if (okay (q , col )) break;
        }
    }
    return 0;
}