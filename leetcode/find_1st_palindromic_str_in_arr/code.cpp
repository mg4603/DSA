#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool isPalindrome(std::string str)
    {
        int n = str.size();
        for(int i = 0; i < n / 2; i++)
        {
            if(str[i] != str[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }
public:
    std::string firstPalindrome(std::vector<std::string>& words) 
    {
        std::ios_base::sync_with_stdio(0);
        for(int i = 0; i < words.size(); i++)
        {
            if(isPalindrome(words[i]))
            {
                return words[i];
            }
        }
        return "";
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"abc","car","ada","racecar","cool"};
        std::string res = "ada";
        assert(sol.firstPalindrome(words) == res);
    }
    {
        std::vector<std::string> words = {"notapalindrome","racecar"};
        std::string res = "racecar";
        assert(sol.firstPalindrome(words) == res);
    }
    {
        std::vector<std::string> words = {"def","ghi"};
        std::string res = "";
        assert(sol.firstPalindrome(words) == res);
    }
    return 0;
}