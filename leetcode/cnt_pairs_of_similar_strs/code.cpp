#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    int similarPairs(std::vector<std::string>& words) 
    {
        std::ios_base::sync_with_stdio(0);

        std::map<int, int> mp;

        for(int i = 0; i < words.size(); i++)
        {
            int bits = 0;
            for(int j = 0; j < words[i].size(); j++)
            {
                bits |= (1 << (words[i][j] - 'a'));
            }
            mp[bits]++;
        }

        int res = 0;
        for(auto it: mp)
        {
            res += (it.second * (it.second - 1))/2;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"aba","aabb","abcd","bac","aabc"};
        int res = 2;
        assert(sol.similarPairs(words) == res);
    }
    {
        std::vector<std::string> words = {"aabb","ab","ba"};
        int res = 3;
        assert(sol.similarPairs(words) == res);
    }
    {
        std::vector<std::string> words = {"nba","cba","dba"};
        int res = 0;
        assert(sol.similarPairs(words) == res);
    }
    return 0;
}