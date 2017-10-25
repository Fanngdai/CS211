#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int k, int n)
{
    // Fill in.  You will probably want to add n as a 3rd parameter.
    
    // Row = position / n
    // Column = position % n
    
    for (int i = 0; i < k; i++)
    {
        // diagonal of the okay function but add n
        if ( abs(q[i]/n - q[k]/n) == abs(q[i]%n - q[k]%n) ) return false;
    }
    return true;
    
    /*
    // This is the code used for the okay queens
     for (int i = 0; i < c; ++i)
        if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
            return false;
    return true;
     */
}

// The function below is from a working n queens program.
// Add a 2nd parameter, k, and modify the function so that it will work for the k bishops program.
// You will have to change the board representation, the condition for
// when to print a solution
// when to backtrack.
int kbishops(int n, int k)
{
    int* q = new int[k]; //q[bishop] is a square on the n*n grid
    int solutions = 0, b = 0, t;
    q[b] = 0;
    
    while(true){ //until we found all the possible solutions
        while(b<k){ //for each bishop
            while(q[b]<n*n){ //for each square
                if(ok(q,b,n)) break;
                else q[b]++;
            }
            
            if(q[b]==n*n)
            {
                b--;
                if (b == -1)
                {
                    cout <<solutions;
                    exit(1);
                }
                // backtrack(b, solutions);
                q[b]++;
                continue;
            }
            
            else
            {
                t = q[b];
                b++;
                q[b] = t;
            }
        }
        solutions++;
        b--;
        if (b == -1)
        {
            cout <<solutions;
            exit(1);
        }
        q[b]++;
    }
}


int main()
{
int n, k;
    // n is the board size
    // k is the amount of bishops you are placing
    while (true)
    {
        cout << "Enter value of n: ";
        cin >> n;
        // if n is neg, do not continue
        if (n == -1) break;
        cout << "Enter value of k: ";
        cin >> k;
        cout << "number of solutions: " << kbishops(n, k) << "\n";
    }
    return 0;
}