#include <algorithm>
#include <iostream>
#include <map>

long long gridTraveler(int n, int m) {
    if(n == 1 && m == 1)return 1;
    if(n == 0 || m == 0)return 0;
    return gridTraveler(n - 1, m) + gridTraveler(n, m - 1);
}

long long memo_gridTraveler(int n, int m, 
            std::map<std::pair<int, int>, long long> &memo) {
    if(n == 1 && m == 1)return 1;
    if(n == 0 || m == 0)return 0;
    if(memo.count({n, m}))return memo[{n, m}];
    memo[{n, m}] = memo[{m, n}] = memo_gridTraveler(n - 1, m, memo) +
                                memo_gridTraveler(n, m - 1, memo);
    return memo[{n, m}];
}

int main()
{
    std::cout << "recursive 3x3: " << gridTraveler(3, 3) << std::endl;
    std::map<std::pair<int, int>, long long> memo;
    std::cout << "memo 3x3: " << memo_gridTraveler(3, 3, memo) << std::endl;
    std::cout << "memo 16x16: " << memo_gridTraveler(16, 16, memo) << std::endl;


    return 0;
}