ss#include <iostream>
#include <vector>
using namespace std;

int main() {
	
    // declare an empty vector of size 3
    vector<int> t[3];
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << "\n";
    // close is the number of spots to move to the right to find the "closest" tower.
    // If n is odd, close = 1 and far = 2.  If n is even, the reverse.
    int close = 1, far = 2;
    // if even of rings
    if (n % 2 == 0)
    	close = 2, far = 1;
    int from = 0, to = close, candidate = 1, move = 0;
   
    // Initialize the towers
    for(int i = n + 1; i >= 1; --i)
        t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);
   
    while (t[1].size() < n+1) { // while t[1] does not contain all of the rings
        cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower ";
      	cout << char(from+'A') << " to tower " << char(to+'A') << "\n";
    // Move the ring from "from" to "to" (first copy it, then delete it from "from")
    t[to].push_back( t[from].back( ) ); // copy
    t[from].pop_back( );             // remove
      
    // from = the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
    // (to+1)%3 goes to the next one on the right
    // (to+2)%3 goes to the one on the left
    if ( t[(to+1)%3].back( ) < t[(to+2)%3].back( ) )
		from = (to+1)%3;
    else
        from = (to+2)%3;
        
    /*
         to = 1     // the destination tower of the previous move
         
         (to + 1) % 3
         
         (to + 2) % 3
         
         if ( t[2].back() < t[0].back() )
         if ( 2 < 4) // then we use 2 because it is true
         if ( true )
    */
         
    // candidate = the ring on top of the from tower
    // is a particular ring. Which you will be moving.
    // copy the last one you moved to candidate
    candidate = t[from].back( );
         
    // to = the closest tower on which the candidate can be placed: (from+close)%3 or (from+far)%3
    if ( t[( from+close ) % 3 ].back( ) > candidate )
    	to = ( from+close )%3;
    else
    	to = ( from+far )%3;
    }
    
    return 0;
}

/*
 to = 1     // the destination tower of the previous move
 
 (to + 1) % 3
 
 (to + 2) % 3
 
 if ( t[2].back() < t[0].back() )
 if ( 2 < 4) // then we use 2 because it is true
 if ( true )
*/