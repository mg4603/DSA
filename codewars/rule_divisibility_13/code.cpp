#include <assert.h>
#include <iostream>

#include <vector>
#include <cmath>
#define ll long long

class Thirteen{
    public:
        static ll thirt(ll n);
};

ll Thirteen::thirt(ll n){
    std::vector<ll> rems = {1, 10, 9, 12, 3, 4};
    ll prev(0);
    while(n != prev){
        ll temp(0);
        prev = n;
        ll count(0);
        while(n){
            temp += rems.at(count % 6) * (n % 10);
            n /= 10;
            count ++;
        }
        n = temp;
    }
    return n;
}

void testing(long long ans, long long sol)
{
    assert(ans == sol);
}

int main(){
    testing(Thirteen::thirt(8529), 79);
    testing(Thirteen::thirt(85299258), 31);
    testing(Thirteen::thirt(5634), 57);
    testing(Thirteen::thirt(1111111111), 71);
    testing(Thirteen::thirt(987654321), 30);
    return 0;
}


