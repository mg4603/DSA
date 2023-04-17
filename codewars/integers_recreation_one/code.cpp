#include <assert.h>
#include <utility>
#include <cmath>
#include <numeric>
#include <vector>
#define ll long long
#include <iostream>

using Result = std::vector<std::pair<long long, long long>>;

class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n);
};


void testequal(const Result& ans, const Result& sol)
{
    assert(ans == sol);
}

void dotest(long long m, long long n, const Result& expected)
{
    testequal(SumSquaredDivisors::listSquared(m, n), expected);
}

int main(){
    dotest(1, 250, {{1, 1}, {42, 2500}, {246, 84100}});
    dotest(42, 250, {{42, 2500}, {246, 84100}});
    dotest(250, 500, {{287, 84100}});
    dotest(300, 600, {});
    return 0;
}


std::vector<std::pair<ll, ll>> SumSquaredDivisors::listSquared(ll m, ll n){

    std::vector<std::pair<ll, ll>> res = std::vector<std::pair<ll, ll>>();
    for(ll i(m); i <=n; i++){
        std::vector<ll> factors = std::vector<ll>();
        for(ll j (1); j <= std::sqrt(i); j++){
            if(i % j == 0){
                factors.push_back(j);
                if(j != i / j)factors.push_back(i / j);
            }
        }
        ll squares = std::accumulate(factors.begin(), factors.end(), 0, [](ll a, ll b){
            return a + pow(b, 2);
        });
        ll square_root = sqrt(squares);

        if((square_root * square_root) == squares){
            res.push_back(std::pair<ll, ll>(i, squares));
        }
    }
    return res;
}