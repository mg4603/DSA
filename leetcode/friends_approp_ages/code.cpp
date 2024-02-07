#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>

class Solution {
    bool request(int a, int b)
    {
        return !((b <= 0.5 * a + 7) || 
                 b > a || 
                 (b > 100 && a < 100));
    }
public:
    int numFriendRequests(std::vector<int>& ages) {
        std::unordered_map<int, int> mp;
        for(int age: ages)
        {
            mp[age]++;
        }

        int res = 0;

        for(auto it: mp)
        {
            for(auto it1: mp)
            {
                if(request(it.first, it1.first))
                {
                    if(it.first == it1.first)
                    {
                        res += it.second * (it.second - 1);
                    }
                    else
                    {
                        res += it.second * it1.second;
                    }
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
        std::vector<int> ages = {16,16};
        int res = 2;
        assert(sol.numFriendRequests(ages) == res);
    }
    return 0;
}