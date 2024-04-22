#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int longestWPI(std::vector<int>& hours) {
        std::ios::sync_with_stdio(0);
        int n = hours.size();
        int prefix = 0;
        int res = 0;
        std::unordered_map<int, int> mp;
        mp[0] = -1;

        for(int i = 0; i < n; i++)        {
            prefix += (hours[i] > 8) ? 1: - 1;
            if(prefix > 0){
                res = i + 1;
            } else{
                if(!mp.count(prefix))
                {
                    mp[prefix] = i;
                }
                if(mp.count(prefix - 1))
                {
                    res = std::max(res, i - mp[prefix - 1]);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> hours = {9,9,6,0,6,6,9};
        int res = 3;
        assert(sol.longestWPI(hours) == res);
    }
    return 0;
}