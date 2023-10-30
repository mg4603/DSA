#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int maximumNumberOfStringPairs(std::vector<std::string>& words) 
    {
        std::unordered_map<std::string, int> mp;
        int res = 0;

        for(int i = 0; i < words.size(); i++)
        {
            if(words[i][0] > words[i][1])
            {
                std::swap(words[i][0], words[i][1]);
            }
            int temp = ++mp[words[i]];
            if(temp % 2 == 0)
            {
                res++;
            }
        }    
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"cd","ac","dc","ca","zz"};
        int res = 2;
        assert(sol.maximumNumberOfStringPairs(words) == res);
    }
    {
        std::vector<std::string> words = {"ab","ba","cc"};
        int res = 1;
        assert(sol.maximumNumberOfStringPairs(words) == res);
    }
    {
        std::vector<std::string> words = {"aa","ab"};
        int res = 0;
        assert(sol.maximumNumberOfStringPairs(words) == res);
    }
    return 0;
}