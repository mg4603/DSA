#include <iostream>
#include <assert.h>

#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
        std::ios_base::sync_with_stdio(0);
        std::map<std::vector<int>, int> mp;
        int count = 0;
        
        for(int i = 0; i < dominoes.size(); i++)
        {
            std::sort(dominoes[i].begin(), dominoes[i].end());

            int temp = ++mp[dominoes[i]];
            if(temp > 1)
            {
                count += (temp - 1);
            }
            
        }

        return count;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> dominoes = {
            {1,2},{2,1},{3,4},{5,6}
        };
        int res = 1;
        assert(sol.numEquivDominoPairs(dominoes) == res);
    }
    {
        std::vector<std::vector<int>> dominoes = {
            {1,2},{1,2},{1,1},{1,2},{2,2},
        };
        int res = 3;
        assert(sol.numEquivDominoPairs(dominoes) == res);
    }
    return 0;
}