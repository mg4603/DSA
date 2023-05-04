#include <assert.h>
#include <iostream>

#include <vector>
#define ull unsigned long long

ull exp_sum(int n) {
    std::vector<ull> dp(n + 1, 0);
    dp[0] = 1;
    if(n < 0){
        return 0;
    }

    for(size_t i(1); i < n + 1; i ++){
        for(size_t j(i); j < n + 1; j++){
            dp[j] += dp[j - i];
        }
    }
    std::cout<<dp.back()<<std::endl;
    return dp.back();
}

int main(){
    assert(exp_sum(1) == 1);
    assert(exp_sum(2) == 2);
    assert(exp_sum(3) == 3);
    assert(exp_sum(4) == 5);
    assert(exp_sum(5) == 7);
    assert(exp_sum(10) == 42);
    return 0;
}