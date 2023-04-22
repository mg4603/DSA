#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#define ull unsigned long long

class Fracts
{

public:
    static std::string convertFrac(std::vector<std::vector<ull>> &lst);
    static ull gcd(ull a, ull b);
};

ull Fracts::gcd(ull a, ull b){
    if(b == 0)return a;
    return gcd(b, a % b);
}

std::string Fracts::convertFrac(std::vector<std::vector<ull>> &lst){
    ull lcm(1);
    for(auto q: lst){
        ull gcd_temp = gcd(q.at(0), q.at(1));
        q[0] /= gcd_temp;
        q[1] /= gcd_temp;
    }
    for(auto q: lst){
        lcm = (lcm * q.at(1)) / gcd(lcm, q.at(1));
    }
    std::string res;
    for(auto q: lst){
        res += '(';
        res += std::to_string(lcm/ q.at(1) * q.at(0));
        res += ',';
        res += std::to_string(lcm);
        res += ')';
    }
    return res;    
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}

int main(){
    std::vector<std::vector<ull>> r1 = { {1, 2}, {1, 3}, {1, 4} };
    std::string ans1 = Fracts::convertFrac(r1);
    std::string sol1 = "(6,12)(4,12)(3,12)";
    testequal(ans1, sol1);
    return 0;
}