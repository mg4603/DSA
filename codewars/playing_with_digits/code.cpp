#include<assert.h>
#include<cmath>
#include<string>
#include<iostream>

class DigPow{
    public:
        static int digPow(int n, int p);
};

void dotest(int n, int p, int expected)
{
    assert(DigPow::digPow(n, p) == (expected));
}

int main()
{
    dotest(89, 1, 1);
    dotest(92, 1, -1);
    dotest(46288, 3, 51);
    dotest(114, 3, 9);
    return 0;   
}

int DigPow::digPow(int n, int p){
    double square(0);
    std::string n_str = std::to_string(n);
    for(char c: n_str){
        square += std::pow((c-'0'), p);
        p += 1;
    }
    if(square / static_cast<double>(n) == std::floor(square / n)){
        return square / n;
    }
    return -1;
}