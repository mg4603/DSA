#include <iostream>

#include <unordered_map>

long long recursive_fib(int n) {
    if(n <= 2)return 1;
    return recursive_fib(n - 1) + recursive_fib(n - 2);
}

long long memo_fib(int n,  
            std::unordered_map<int, long long> &memo) {
    if(memo.count(n))return memo[n];
    if(n <= 2)return 1;
    memo[n] = memo_fib(n - 1, memo) + memo_fib(n - 2, memo);
    return memo[n];
}

int main() {
    std::unordered_map<int, long long> mp;
    std::cout << memo_fib(50, mp) << std::endl;
    return 0;
}