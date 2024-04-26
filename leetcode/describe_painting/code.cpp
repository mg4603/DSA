#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::vector<long long>> splitPainting(
                        std::vector<std::vector<int>>& segments) {
        std::ios::sync_with_stdio(0);
        std::map<int, long long> mp;
        for(int i = 0; i < segments.size(); i++)
        {
            mp[segments[i][0]] += segments[i][2];
            mp[segments[i][1]] -= segments[i][2];
        }
        
        std::vector<std::vector<long long>> res;
        int i = 0;
        for(auto &it: mp)
        {
            if(mp[i] > 0)
            {
                res.push_back({i, it.first, mp[i]});
            }
            mp[it.first] += mp[i];
            i = it.first;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> segments = {{1,4,5},{4,7,7},{1,7,9}};
        std::vector<std::vector<long long>> res = {{1,4,14},{4,7,16}};
        assert(sol.splitPainting(segments) == res);
    }
    return 0;
}