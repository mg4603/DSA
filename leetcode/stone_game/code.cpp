#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int helper(std::vector<int> &piles, int l, int r,  
                std::vector<std::vector<int>> &table)
    {
        if(l == r - 1)return std::max(piles[l], piles[r]);

        if(table[l][r] != -1)return table[l][r];

        int left = piles[l] + std::max(-piles[r] + 
                                    helper(piles, l + 1, r - 1, table), 
                                -piles[l + 1] + 
                                    helper(piles, l + 2, r, table));
        int right = piles[r] + std::max(-piles[l] + 
                                    helper(piles, l + 1, r - 1, table), 
                                -piles[r - 1] + 
                                    helper(piles, l, r - 2, table));
        table[l][r] = std::max(left, right);
        return table[l][r];
    }
public:
    bool stoneGame(std::vector<int>& piles) {
        int n = piles.size();
        std::vector<std::vector<int>> table(n, 
                std::vector<int>(n, -1));
        return helper(piles, 0, n - 1, table) > 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> piles = {5,3,4,5};
        bool res = true;
        assert(sol.stoneGame(piles) == res);
    }
    return 0;
}