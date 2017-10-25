#include <iostream>
using namespace std;

unsigned long long int fib ( int n )
{
    static unsigned long long int memo[100] = {0,1,1};
    if (memo[n] != 0) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}

int main()
{
    for(int i=1; i<99; i++)
        cout<<" fib("<<i<<") = "<<fib(i)<<endl;
    return 0;
}
