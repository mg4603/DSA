#include <iostream>
#include <assert.h>

class Solution {
    int helper(std::string str)
    {
        int res = 0;
        for(int i = 0; i < str.length(); i++)
        {
            res *= 10;
            res += (str[i] - 'a');
        }
        return res;
    }
public:
    bool isSumEqual(std::string firstWord, std::string secondWord, 
                    std::string targetWord) {
        int first = helper(firstWord);
        int second = helper(secondWord);
        int target = helper(targetWord);
        
        return first + second == target;
    }
};

int main()
{
    Solution sol;
    {
        std::string firstWord = "acb";
        std::string secondWord = "cba";
        std::string targetWord = "cdb";
        bool res = true;
        assert(sol.isSumEqual(firstWord, secondWord, targetWord) == res);
    }
    {
        std::string firstWord = "aaa";
        std::string secondWord = "a";
        std::string targetWord = "aab";
        bool res = false;
        assert(sol.isSumEqual(firstWord, secondWord, targetWord) == res);
    }
    {
        std::string firstWord = "aaa";
        std::string secondWord = "a";
        std::string targetWord = "aaaa";
        bool res = true;
        assert(sol.isSumEqual(firstWord, secondWord, targetWord) == res);
    }
    return 0;
}