#include <stack>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#define ll long long
class Decomp
{
  public:
  static std::vector<ll> decompose(ll n);
};

std::vector<ll> Decomp::decompose(ll n){
    std::vector<ll> result;
    result.push_back(n);
    ll goal(0), current;
    while(result.size()){
        current = result.back();
        result.pop_back();
        goal += current * current;
        for(ll i(current - 1); i > 0; i--){
            if(goal - (i * i) >= 0){
                goal -= (i * i);
                result.push_back(i);
                if(goal == 0){
                    std::sort(result.begin(), result.end());
                    return result;
                }
            }
        }
    }
    return {};
}


void printVector(const std::vector<ll> &vec){
    for(ll num: vec){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
}
bool issorted(std::vector<ll>::iterator it1, std::vector<ll>::iterator it2){
    std::vector<ll> new_vec;
    std::copy(it1, it2, std::back_inserter(new_vec));
    std::sort(new_vec.begin(), new_vec.end());
    for(size_t i(0); i < new_vec.size(); i++){
        if(*(it1 + i) != new_vec.at(i))return false;
    }

    return true;
}
void testing(ll n, std::vector<ll> sol)
{
    std::vector<ll> ans = Decomp::decompose(n);
    bool success = false;
    if ( ans == sol ) {
        printVector(ans);
        printVector(sol);
        std::cout << "GOOD\n";
        success = true;
    } else {
        if (ans.empty() || (ans.size() >= 1 && ans[0] == n)) {
            printVector(ans);
            printVector(sol);
            std::cout << "Bad answer\n";
            success = false;
        } else {
            bool st = issorted(ans.begin(), ans.end());
            long long tot = std::inner_product( ans.begin(), ans.end(), ans.begin(), 0LL );
            bool t = (tot == n * n);
            if ((st == false) || (t == false)) {
                std::cout << "** Error. Not increasinly sorted or bad sum of squares\n **";
                printVector(ans);
                printVector(sol);
                std:: cout << "Sorted: " << st << " Total: " << tot << " Wanted: " << n*n << std::endl;
                success = false;
            } else {
                std::cout << "GOOD: Increasing and total correct\n";
                success = true;
            }
        }
    }
    assert(success == true);
}
int main(){
    testing(50, {1,3,5,8,49});
    testing(44, {2,3,5,7,43});
    testing(2, {});
    return 0;
}
