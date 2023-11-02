#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void helper(std::vector<std::string> &mapping, 
                std::vector<std::string> &res, 
                std::string &digits, int i, 
                std::string temp)
    {
        if(i == digits.size())
        {
            if(temp != "")
            {
                res.push_back(temp);
            }
            return;
        }

        for(int j = 0; j < mapping[digits[i] - '0'].size(); j++)
        {
            helper(mapping, res, digits, i + 1, 
                    temp + std::string(1, mapping[digits[i] - '0'][j]));
        }
    }
public:
    std::vector<std::string> letterCombinations(std::string digits) 
    {
        std::vector<std::string> mapping{"0", "0", "abc", "def", 
                                         "ghi", "jkl", "mno", 
                                         "pqrs", "tuv", "wxyz"};

        std::vector<std::string> res;

        helper(mapping, res, digits, 0, "");
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string digits = "23";
        std::vector<std::string> res = {"ad","ae","af",
                                        "bd","be","bf",
                                        "cd","ce","cf"};
        assert(sol.letterCombinations(digits) == res);
    }
    {
        std::string digits = "";
        std::vector<std::string> res = {};
        assert(sol.letterCombinations(digits) == res);
    }
    {
        std::string digits = "2";
        std::vector<std::string> res = {"a","b","c"};
        assert(sol.letterCombinations(digits) == res);
    }
    return 0;
}