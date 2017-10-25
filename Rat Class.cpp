// Rat class i.e. a class for rational numbers
#include <iostream>
#include <cmath>
using namespace std;

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

int main() {
    Rat r1(-1, 2), r2(3, 2);
    
    cout << "r1: \t\t" << r1 << endl;
    cout << "r2: \t\t" << r2 << endl;
    cout << "r1 + r2: \t" << r1 + r2 << endl;
    cout << "r1 - r2: \t" << r1 - r2 << endl;
    cout << "r1 * r2: \t" << r1 * r2 << endl;
    cout << "r1 / r2: \t" << r1 / r2 << endl;
    cout << endl;
    
    r1 = r2;
    r2 = r1 * r2;
    
    cout << "r1: \t\t" << r1 << endl;
    cout << "r2: \t\t" << r2 << endl;
    cout << "r1 + r2: \t" << r1 + r2 << endl;
    cout << "r1 - r2: \t" << r1 - r2 << endl;
    cout << "r1 * r2: \t" << r1 * r2 << endl;
    cout << "r1 / r2: \t" << r1 / r2 << endl;
    cout << endl;
    
    r1 = r2 + r1 * r2 / r1;
    r2 = r2 + r1 * r2 / r1;
    
    cout << "r1: \t\t" << r1 << endl;
    cout << "r2: \t\t" << r2 << endl;
    cout << "r1 + r2: \t" << r1 + r2 << endl;
    cout << "r1 - r2: \t" << r1 - r2 << endl;
    cout << "r1 * r2: \t" << r1 * r2 << endl;
    cout << "r1 / r2: \t" << r1 / r2 << endl;
    
    return 0;
}
