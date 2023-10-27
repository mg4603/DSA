#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool checkDistances(std::string s, std::vector<int>& distance) 
    {
        std::vector<std::vector<int>> dists(26);
        for(int i = 0; i < s.length(); i++)
        {
            dists[s[i] - 'a'].push_back(i);
        }

        for(int i = 0; i < 26; i++)
        {
            if(dists[i].size() == 0)continue;
            int temp = dists[i][1] - dists[i][0] - 1;
            if(temp != distance[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abaccb";
        std::vector<int> distance = {1,3,0,5,0,0,0,0,0,0,0,0,0,
                                     0,0,0,0,0,0,0,0,0,0,0,0,0};
        int res = true;
        assert(sol.checkDistances(s, distance) == res);
    }
    {
        std::string s = "aa";
        std::vector<int> distance = {1,0,0,0,0,0,0,0,0,0,0,0,0,
                                     0,0,0,0,0,0,0,0,0,0,0,0,0};
        int res = false;
        assert(sol.checkDistances(s, distance) == res);
    }
    return 0;
}