#include <assert.h>
#include <iostream>

#include <vector>
#include <utility>

class SumFractions
{
public:
    static std::pair <int, int> sumFracts(std::vector<std::vector<int>> &l);
    static int gcd(int a, int b);
};

int SumFractions::gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

std::pair <int, int> SumFractions::sumFracts(std::vector<std::vector<int>> &l){
    if(l.size() == 0){
        return std::make_pair(0, 1);
    }
    long long numerator(0);
    long long denominator(1);

    for(auto rational: l){

        int gcdPQ = gcd(rational.at(0), rational.at(1));
        rational[0] /= gcdPQ;
        rational[1] /= gcdPQ;

        int oldDenom = denominator;
        int gcdDenomQ = gcd(rational.at(1), denominator);
        denominator *= (rational[1] / gcdDenomQ);
        numerator = (numerator * (rational[1] / gcdDenomQ)) + (rational[0] * (oldDenom / gcdDenomQ));
        
    }

    int gcdPQ = gcd(numerator, denominator);
    numerator /= gcdPQ;
    denominator /= gcdPQ;
    return std::make_pair(numerator, denominator);
}

void testequal(std::pair <int, int> ans, std::pair <int, int> sol) {
    assert(ans == sol);
}

int main(){
    std::vector<std::vector<int>> a1 = { {1,2}, {2,9}, {3,18}, {4,24}, {6,48} };
    testequal(SumFractions::sumFracts(a1), {85, 72});
    std::vector<std::vector<int>> a2 = { {1, 2}, {1, 3}, {1, 4} };
    testequal(SumFractions::sumFracts(a2), {13, 12});
    std::vector<std::vector<int>> a3 = { {1, 3}, {5, 3} };
    testequal(SumFractions::sumFracts(a3), {2, 1});
    std::vector<std::vector<int>> a4 = { };
    testequal(SumFractions::sumFracts(a4), {0, 1});
    return 0;
}
        
