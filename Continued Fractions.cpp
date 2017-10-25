// Rat class i.e. a class for rational numbers
#include <iostream>
#include <cmath>
using namespace std;

// Start of Rat Class
// Calculate the GCD (Euclid's algorithm)
int gcd(int n, int d){
    return d == 0 ? n : gcd(d, n%d);
}

class Rat{
private:
    int n;
    int d;
    
public:
    // constructors
    
    // default constructor
    
    /*
     Also known as an no argument constructor
     Which takes no parameters
     Will create a new object
     Inside this, each object has it's own n and d
     rat x; <- we do this in c++
     Rat x = new Rat( ); <- this in java
     */
    
    Rat(){
        n=0;
        d=1;
    }
    
    // 2 parameter constructor
    Rat(int i, int j){
        n=i;
        d=j;
        reduce( );
    }
    
    // conversion constructor
    Rat(int i){
        n=i;
        d=1;
    }
    
    //accessor functions (usually called get() and set(...) )
    int getN(){ return n;}
    int getD(){ return d;}
    
    void setN(int i){ n=i;}
    void setD(int i){ d=i;}
    
    //arithmetic operators
    Rat operator+(Rat r){
        Rat t;
        t.n = n*r.d + d*r.n;
        t.d = d*r.d;
        t.reduce( );
        return t;
    }
    
    // Write the other 3 operators (operator-, operator*, operator/).
    Rat operator- (Rat r)
    {
        Rat t;
        t.n = n*r.d - d*r.n;
        t.d = d*r.d;
        t.reduce( );
        return t;
        
    }
    
    Rat operator* (Rat r)
    {
        Rat t;
        t.n = n * r.n;
        t.d = d * r.d;
        t.reduce( );
        return t;
    }
    
    Rat operator/ (Rat r)
    {
        Rat t;
        t.n = n * r.d;
        t.d = d * r.n;
        t.reduce( );
        return t;
    }
    
    // Write a function to reduce the Rat to lowest terms, and then you can call this function from other functions.
    // Rat x(2,4); should be prints as 1/2
    void reduce( )
    {
        // make sure denominator is positive!
        // if d is neg, flip the sign of n & d
        if ( d < 0)
        {
            n = -n;
            d = -d;
        }
        
        int g = gcd(n,d);
        // divide n & d by the gcd
        n /= g;
        d /= g;
    }
    // Also make sure that the denominator is positive.  Rats should be printed in reduced form.
    
    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r)
{
    // this function has access to private members n and d
    // Rewrite this function so that improper fractions are printed as mixed numbers.  For example:
    // 3/2 should be printed as 1 1/2
    // 1/2 should be printed as 1/2
    // 2/1 should be printed as 2
    // 0/1 should be printed as 0
    // Negative numbers should be printed the same way, but beginning with a minus sign
    
    // if r.n is 0, the whole thing is 0
    if(r.n == 0)
        os << r.n;
    
    // if the top is bigger than the bottom then we gotta do something to reduce it
    // d can be reduced to 1
    // therefore, we top/bottom and return that
    else if( abs(r.n) >= abs(r.d) && r.n%r.d == 0)
        os << r.n / r.d;
    
    // d cannot be reduced to 1
    // then we divide it.
    // That's the whole number
    else if( r.n >= r.d && r.n%r.d != 0 && r.n/r.d != 0)
        os << r.n/r.d <<" "<< (r.n%r.d) / gcd(r.n % r.d,r.d) << "/" << abs( (r.d)/gcd(r.n % r.d,r.d) );
    
    // all the above didn't work
    // that means that nothing needs to be done to the rat
    else
    {
        if ( r.d/gcd(r.n%r.d,r.d) < 0 )
            os << - (r.n/gcd(r.n%r.d,r.d)) << "/" << -(r.d/gcd(r.n%r.d,r.d));
        else
            os << r.n/gcd(r.n%r.d,r.d) << "/" << r.d/gcd(r.n%r.d,r.d);
    }
    
    return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
istream& operator>>(istream& is, Rat& r){
    is >> r.n >> r.d;
    return is;
}
//End of Rat Class

double continued_frac_1(int a[], int i)
{
    double x = a[i], y = 1.0;
    // first check if you are in the base case
    // if you arem return the element at index 1
    if ( a[++i] == -1 ) return x;
    // call the function recursively and do the calculation
    return ( x + y / continued_frac_1( a, i ));
}
/*
 f(array,0)
 |
 return array[0] + 1 / f(array,1) // i = 0
 |
 return array[1] + 1 / f(array,2) // i = 1
 |
 16 // i = 2
 // base case because a[i+1] is -1
 */
Rat continued_frac_3(int a[], int i);

int* continued_frac_2(int a[], int i)
{
    // An array of size 3. Set equal to zero for each array.
    static int b[2] = { };
    int temp;
    
    // base case
    // After we use up the three numbers given from the main function, we end the function because we are done
    if( i == 2 )
    {
        b[1] = 1;
        b[0] = a[2];
        return b;
    }
    
    // if the if statement above doesn't work, else...
    continued_frac_2(a, i+1);
    temp = b[0];
    // http://mathworld.wolfram.com/ContinuedFraction.html
    // a0 * p(a1 .... an) + q(a1 .... an)
    b[0] = a[i] * temp + b[1];
    b[1] = temp;
    return b;
    
    /*
     For the 2nd function, first create a dynamic 2-element array (it has to be dynamic so that it will continue to exist after the function returns).
     Then call the 3rd function which returns a Rat.
     Then call the Rat's get functions to get the numerator and denominator, put those 2 numbers into the array, and then return the array.
     
     I give up lol Maybe do it
     int* p = new int[2];
     Rat b(continued_frac_3(a, i+1));
     */
    
}

Rat continued_frac_3(int a[], int i)
{
    /*
     // one way to do this using the above function
     // get the answer for frac 2 (above function)
     // pointer because program told me so... lol
     // But it works and that's all that matters
     int * b = continued_frac_2(a, i);
     // This gets the n & d from the above function
     
     // declares an Rat. Changing integer to a Rat.
     Rat toBeReturned( b[0], b[1]);
     return toBeReturned;
     */
    
    // used Aliza's wrong code as reference
    // base case
    if ( a[i+1] == -1 )
    {
        Rat toBeReturned(a[i]);
        return toBeReturned;
    }
    
    // declares the array as an array
    Rat b(a[i]);
    // declaring denominator as a Rat instead of an integer.
    Rat d(continued_frac_3(a, i+1).getD());
    // Have to do the same to numerator
    Rat n( continued_frac_3(a, i+1).getN());
    
    // because 1/ the whole function
    // so we have to flip it
    // watch waxman's video to understand.
    Rat p = n / d;
    Rat one = 1;
    Rat reverse = one / p;
    Rat q = reverse + b;
    return q;
}

int main() {
    int array[] = {3, 7, 16, -1};
    
    cout << "Continued fractions function 1: " <<
    continued_frac_1(array, 0) << endl;
    
    int *a = continued_frac_2(array, 0);
    cout << "Continued fractions function 2: " <<
    a[0] << '/' << a[1] << endl;
    // delete []a;
    
    cout << "Continued fractions function 3: " <<
    continued_frac_3(array, 0) << endl;;
    
    return 0;
}

/*
 Continued fractions function 1: 3.14159
 Continued fractions function 2: 355/113
 Continued fractions function 3: 3 16/113
 */