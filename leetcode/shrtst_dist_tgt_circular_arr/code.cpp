#include <iostream>
#include <assert.h>

#include <limits>
#include <vector>

class Solution {
public:
    int closetTarget(std::vector<std::string>& words, 
                     std::string target, 
                     int startIndex) 
    {
        int n = words.size();
        int res = std::numeric_limits<int>::max();
        for(int i = 0; i < n; i++)
        {
            if(words[(startIndex + i) % n] == target)
            {
                if(i < res)
                {
                    res = i;
                }
            }
            if(words[(n + startIndex - i) % n] == target)
            {
                if(i < res)
                {
                    res = i;
                }
            }
        }
        if(res == std::numeric_limits<int>::max())
        {
            return -1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"hello","i","am","leetcode","hello"};
        std::string target = "hello";
        int startIndex = 1;
        int res = 1;
        assert(sol.closetTarget(words, target, startIndex) == res);
    }
    {
        std::vector<std::string> words = {"a","b","leetcode"};
        std::string target = "leetcode";
        int startIndex = 0;
        int res = 1;
        assert(sol.closetTarget(words, target, startIndex) == res);
    }
    {
        std::vector<std::string> words = {"i","eat","leetcode"};
        std::string target = "ate";
        int startIndex = 0;
        int res = -1;
        assert(sol.closetTarget(words, target, startIndex) == res);
    }
    return 0;
}