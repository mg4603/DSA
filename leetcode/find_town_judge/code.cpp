#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        std::ios::sync_with_stdio(0);
        if(trust.empty() && n == 1)
        {
            return 1;
        }
        
        std::unordered_map<int, int> trusted;
        std::unordered_set<int> residents;
        for(int i = 0; i < trust.size(); i++)
        {
            trusted[trust[i][1]]++;
            residents.insert(trust[i][0]);
        }
        
        for(auto pair: trusted)
        {
            if(pair.second == n - 1 && residents.find(pair.first) == residents.end())
            {
                return pair.first;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        std::vector<std::vector<int>> trust = {
            {1,2}
        };

        int res = 2;
        assert(sol.findJudge(n, trust) == res);
    }
    {
        int n = 3;
        std::vector<std::vector<int>> trust = {
            {1,3}, {2,3},
        };
        
        int res = 3;
        assert(sol.findJudge(n, trust) == res);
    }
    {
        int n = 3;
        std::vector<std::vector<int>> trust = {
            {1,3},{2,3},{3,1}
        };
        
        int res = -1;
        assert(sol.findJudge(n, trust) == res);
    }
    return 0;
}