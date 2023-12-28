#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <map>

class Solution {
    int solve(std::vector<int> prev, std::vector<int> &price, 
              std::vector<std::vector<int>> &special, 
              std::vector<int> needs, int idx, 
              std::unordered_map<int, 
                        std::map<std::vector<int>, int>> &table)
    {
        if(idx == special.size())
        {
            int res = 0;
            for(int i = 0; i < needs.size(); i++)
            {
                res += (needs[i]-prev[i]) * price[i];
            }
            return res;
        }

        if(table.count(idx) && table[idx].count(prev))
        {
            return table[idx][prev];
        }
        int reject = solve(prev, price, special, 
                            needs, idx + 1, table);

        std::vector<int> curr = prev;
        for(int i = 0; i < needs.size(); i++)
        {
            if(curr[i] + special[idx][i] <= needs[i])
            {
                curr[i] += special[idx][i];
            }
            else
            {
                table[idx][prev] = reject;
                return table[idx][prev];
            }
        }

        int accept = special[idx][needs.size()] + 
                        solve(curr, price, special, 
                                needs, idx, table);

        table[idx][prev] = std::min(reject, accept);
        return table[idx][prev];
    }
public:
    int shoppingOffers(std::vector<int>& price, 
                       std::vector<std::vector<int>>& special, 
                       std::vector<int>& needs) 
    {
        std::unordered_map<int, 
                    std::map<std::vector<int>, int>> table;
        std::vector<int> curr(needs.size(), 0);
        return solve(curr, price, special, needs, 0, table);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> price = {2,5};
        std::vector<std::vector<int>> special = {{3,0,5},{1,2,10}};
        std::vector<int> needs = {3,2};
        int res = 14;
        assert(sol.shoppingOffers(price, special, needs) == res);
    }
    {
        std::vector<int> price = {2,3,4};
        std::vector<std::vector<int>> special = {{1,1,0,4},{2,2,1,9}};
        std::vector<int> needs = {1,2,1};
        int res = 11;
        assert(sol.shoppingOffers(price, special, needs) == res);
    }
    return 0;
}