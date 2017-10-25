#include <iostream>
#include <cstring>
using namespace std;

void swap( char array[ ], char i, char j)
{
    char temp;
    temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

int minIndex (char array[ ], int x, int y)
{
    int min = x;
    for( int i = x; i <= y; i++)
        if( array[i] < array[min]) min = i;
    return min;
}

void sort( char array[ ], int length)
{
    int minInd;
    for( int i = 0; i < length; i++)
    {
        minInd = minIndex(array, i, length-1);
        swap(array, minInd, i);
    }
}



int main ()
{
label:

	string outcome;
	// score of each team
	double score [ 'Z' + 1 ] = { };
	// Who are there teams? (Letter)
    char teams [ 'Z' + 1 ] = { };
    // Amount teams in total
    int teams_amt = 0;
    // amount of runners per team
    int runners [ 'Z' + 1 ] = { };
    double rank;
    char winner;


	// askes user for race outcome
	cout << "Enter the race outcome: ";
	// saves outcome
	cin >> outcome;
	// end program if user enters done
	if ( outcome == "done") return 0;
	
	
	for (int i = 0; i < outcome.length( ); i++)
	{
	    if (score [ outcome [ i ] ] == 0)
	    {
	        // stores team (letter)
	        teams[ teams_amt ] = outcome [i];
	        // counts the teams
	        teams_amt ++;
	    }
	    
        // scores each runner
	    score [ outcome [ i ] ] += ( i + 1 );
	    
	    // counts runners
	    runners [ outcome [i] ] ++;
	}
	
	
	// find average of each team
	for (int j = 0; j < outcome.length( ) ; j++)
	{
	    // Checking if each team has same amount of runners
	    while ( outcome.length( ) / teams_amt != runners[ outcome [j]] )
	    {
	        cout << "The teams don't have the same number of runners.\n\n";
	        // If each team doesn't have same amt of runners, restart program
	        goto label;
	    }
	    // finding average of each team
	    score [ teams [j] ] /= runners[ outcome [ 0 ]];    
	}
	
	// setting the rank & winner to first team (will be replaced)
	rank = score [ teams [0]];
	winner = teams [0];
	        
	for (int k = 0; k < teams_amt ; k++)
	{
	    // if a team is higher in ranking
	    if ( score [ teams [k] ] < rank )
	    {
	        // rank is set to lower score
	        rank = score [ teams [k]];
	        // winner is switched
	        winner = teams [k];
	    }
	}

	
	cout << "There are " << teams_amt << " teams.\n";
	cout << "Each team has " << runners[ outcome [0] ] << " runners.\n";
	sort( teams, teams_amt);
	for (int l = 0; l < teams_amt ; l++)
	{
        cout << teams[l] << ": " << score[ teams [l] ] << endl;
	}
    cout << "The winning team is team " << winner << " with score " << rank << endl;
	
	
    cout << endl;
    goto label;
}