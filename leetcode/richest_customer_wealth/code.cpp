#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) 
    {
        int res = 0;
        for(int i = 0; i < accounts.size(); i++)
        {
            int temp = std::accumulate(accounts[i].begin(), 
                                       accounts[i].end(), 0);
            if(temp > res)
            {
                res = temp;
            }        
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> accounts = {
                                        {1,2,3},{3,2,1}};
        int res = 6;
        assert(sol.maximumWealth(accounts) == res);
    }
    {
        std::vector<std::vector<int>> accounts = {
                                        {1,5},{7,3},{3,5}};
        int res = 10;
        assert(sol.maximumWealth(accounts) == res);
    }
    {
        std::vector<std::vector<int>> accounts = {
                                        {2,8,7},{7,1,3},{1,9,5}};
        int res = 17;
        assert(sol.maximumWealth(accounts) == res);
    }
    return 0;
}