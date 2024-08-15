#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>

class Solution {
public:
    long long dividePlayers(std::vector<int>& skill) {
        std::ios::sync_with_stdio(0);
        std::unordered_map<int, int> mp;
        int n = skill.size();
        int avg = 0;
        for(int &it: skill) {
            mp[it]++;
            avg += it;
        }
        avg = (avg / (n / 2));

        long long res = 0;
        for(int &it: skill) {
            if(mp[avg - it]-- > 0) {
                res += ((avg - it) * it);
            }
            else {
                return -1;
            }
        }
        return res / 2;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> skill = {3,2,5,1,3,4};
        int res = 22;
        assert(sol.dividePlayers(skill) == res);
    }
    return 0;
}