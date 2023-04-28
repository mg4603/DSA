#include <assert.h>
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>
#define ll long long

class ToSmallest
{
public:
    static std::vector<long long> smallest(long long n);
};

std::vector<ll> ToSmallest::smallest(ll n){
 std::string str_n = std::to_string(n);
 std::vector<std::vector<ll>> permutations{{n, 0, 0}};
 for(ll i(0); i < str_n.length(); i++){
    for(ll j(0); j < str_n.length(); j++){
        std::string temp_str = str_n;
        temp_str.erase(i, 1);
        temp_str.insert(j, 1, str_n[i]);
        permutations.push_back({std::stoll(temp_str), i, j});
    }
 }
 return *std::min_element(permutations.begin(), permutations.end());
}

void testequal(std::vector<long long> ans, std::vector<long long> sol)
{
    assert(ans == sol);
}
static void dotest(long long n, std::vector<long long> expected)
{
    testequal(ToSmallest::smallest(n), expected);
}

int main()
{
    dotest(261235, {126235, 2, 0});
    dotest(209917, {29917, 0, 1});
    dotest(285365, {238565, 3, 1});
    dotest(269045, {26945, 3, 0});
    dotest(296837, {239687, 4, 1});
    return 0;
}
