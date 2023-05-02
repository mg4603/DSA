#include <assert.h>
#include <iostream>

#include <vector>
#include <numeric>
#define ll long long

class Operarray{
    public:
        static ll gcdi(ll x, ll y);
        static ll lcmu(ll a, ll b);
        static ll som(ll a, ll b);
        static ll maxi(ll a, ll b);
        static ll mini(ll a, ll b);

        static ll oper(ll (*f)(ll a, ll b), ll a, ll b);

        static std::vector<ll> operArray(ll (*f)(ll a, ll b), std::vector<ll> &arr, ll init);

};

ll Operarray::gcdi(ll x, ll y){
    if(x < 0){
        x = -x;
    }
    if (y < 0){
        y = -y;
    }
    if(y == 0){
        return x;
    }
    return gcdi(y, x % y);
}

ll Operarray::lcmu(ll a, ll b){
    if(a < 0){
        a = -a;
    }
    if (b < 0){
        b = -b;
    }
    ll res = gcdi(a, b);
    res *= (a / res) * (b / res);
    return res;
}

ll Operarray::som(ll a, ll b){
    return a + b;
}

ll Operarray::maxi(ll a, ll b){
    return std::max(a, b);
}

ll Operarray::mini(ll a, ll b){
    return std::min(a, b);
}

ll Operarray::oper(ll (*f)(ll a, ll b), ll a, ll b){
    return f(a, b);
}

std::vector<ll> Operarray::operArray(ll (*f)(ll a, ll b), std::vector<ll> & arr, ll init){
    std::vector<ll> res;
    for(size_t i(0); i < arr.size(); i++){
        init = f(init, arr[i]);
        res.push_back(init);
    }
    return res;
}

void testequal(std::vector<long long> ans, std::vector<long long> sol)
{
    assert(ans == sol);
}
template<typename Func>
static void dotest(Func func, std::vector<long long> &arr, long long init, std::vector<long long> expected)
{
    testequal(Operarray::operArray(func, arr, init), expected);
}

int main()
{
    std::vector<long long> dta = { 18, 69, -90, -78, 65, 40 };
    std::vector<long long> sol = { 18, 3, 3, 3, 1, 1 };
    dotest(Operarray::gcdi, dta, dta[0], sol);
    sol = { 18, 414, 2070, 26910, 26910, 107640 };
    dotest(Operarray::lcmu, dta, dta[0], sol);
    sol = { 18, 69, 69, 69, 69, 69 };
    dotest(Operarray::maxi, dta, dta[0], sol);
    sol = { 18, 18, -90, -90, -90, -90 };
    dotest(Operarray::mini, dta, dta[0], sol);
    sol = { 18, 87, -3, -81, -16, 24 };
    dotest(Operarray::som, dta, 0, sol);
    return 0;
}
