#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int rows = 5, cols = 6;
int minRow, minLength;
string path[rows][cols];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
    static int weight[rows][cols] =
    {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
    };
    
    
    // Declare the cost matrix.
    static int cost[rows][cols] = { };
    // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
    for (int i = 0; i < 5; i++)
    {
        cost[i][0] = weight[i][0];
        path[i][0] = to_string(i);
    }
    // For each remaining column,
    // Calculate the cost of each square in the column (non-recursively),
    // and store the correct number in the cost matrix and the correct string in the path matrix.
    
    int up, left, down, minCost, j = 1;
    while (j < cols) {
        for (int i = 0; i < rows; i++)
        {
            up = cost[(i-1+rows)%rows][j-1];
            left = cost[i][j-1];
            down = cost[(i+1)%rows][j-1];
            minCost = up;
                
            // up is min
            if(minCost > down)
            {
                minCost = down;
                path[i][j] = path[(i+1)%rows][j-1] + to_string(i);
            }
            
            if(minCost > left)
            {
                minCost = left;
                path[i][j] = path[i][j-1] + to_string(i);
            }
            
            if(minCost == up)
                path[i][j] = path[(i+rows-1)%rows][j-1] + to_string(i);
            
            cost[i][j] = minCost + weight[i][j];
        }
        j++;
    }

    // Check which square in the rightmost column has the lowest cost.  Store that cost in minLength and the row number in minRow.
    minLength = cost[0][cols-1];
    for ( int i = 0; i < rows; i++ )
    {
        if ( minLength > cost[i][cols-1])
        {
            minRow = i;
            minLength =cost[i][cols - 1];
        }
        // cost[i][j] = weight[i][j] + minCost;
    }
}

int main() {
    calculateCosts();
    cout << "The length of the shortest path is " << minLength;
    cout << ".\nThe rows of the path from left to right are " << path[minRow][cols-1] << ".";
    
    return 0;
}