#include <assert.h>
#include <iostream>

#include <string>
#include <cmath>
#include <sstream>

class Carboat{
    public:
    static std::string howmuch(int m, int n);
};

std::string Carboat::howmuch(int m, int n){
    if (m > n){
        std::swap(m, n);
    }
    std::stringstream ss;
    ss << '[';
    for(int i(m); i <= n; i++){
        double c((i - 1) / 9.0);
        double b((i - 2) / 7.0);
        if(std::round(c) == c && std::round(b) == b){
            ss << "[M: " << i << " B: " << b << " C: "<< c <<']';
        }
    }
    ss << ']';
    return ss.str();
}

void test1()
{
    std::string ans1 = Carboat::howmuch(1, 100);
    std::string sol1 = "[[M: 37 B: 5 C: 4][M: 100 B: 14 C: 11]]";
    assert(ans1 == sol1);
}
void test2()
{
    std::string ans1 = Carboat::howmuch(2950, 2950);
    std::string sol1 = "[]";
    assert(ans1 == sol1);
}
void test3()
{
    std::string ans1 = Carboat::howmuch(20000, 20100);
    std::string sol1 = "[[M: 20008 B: 2858 C: 2223][M: 20071 B: 2867 C: 2230]]";
    assert(ans1 == sol1);
}

int main(){
    test1();
    test2();
    test3();
}