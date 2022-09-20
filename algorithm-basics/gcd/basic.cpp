#include<iostream>
using namespace std;

// find the greatest common divisor of a and b
// GCD(a,b) = GCD(b, a mod b)
template<typename T>
T gcd(T a, T b){
    while(b != 0){
        T remainder = a % b;
        a = b;
        b = remainder;
    }
    return a; // gcd(a,0) is a
}

int main(){
    cout<<gcd<int>(6,3);
    return 0;
}