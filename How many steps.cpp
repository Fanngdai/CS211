#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <set>
using namespace std;

int main() {
   ifstream in("steps-input.txt");
   int numSets, temp;	
   in >> numSets;                                    // Get the number of data sets.
   for (int i = 1; i <= numSets; ++i) {              // For each data set i,
      	in >> temp;                                  // Get the data set number (which will be the same as i).
      	int steps = 0;                               // Initialize the number of steps.
      	//vector<int> set;                           // Initialize a container (e.g. array, vector, set, whatever you think will be most useful)
      	set<int> container;
      	
      	for (int j = 1; j <= 20; ++j) {              // For each of the 20 students,
        // Get the height.
        in >> temp;
        //set.push_back(temp);
        // Calculate the number of steps, update steps, and add the height to the container.
        steps += distance( container.insert(temp).first , container.end( )) - 1;             
		
		//for(int k : set) if( temp < k) steps++;
      	}
      cout << i << " " << steps << endl;             // Print the data set number followed by the number of steps.
   }
   in.close();
   return 0;
}