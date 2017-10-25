#include <iostream>
using namespace std;

int main()
{
    int n;
    int count = 1;
    int add = count;
    
    cout << "Please enter the number of rows: ";
    cin >> n;
    
    while ( n >= count)
    {
        
        add = count;
    
        while ( add <= count * count)
        {
            cout << add << "\t";
            add += count;
        }
        
        ++count;
        cout << endl;
    }
    return 0;
}