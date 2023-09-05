#include <iostream>
#include <assert.h>

#include <algorithm>
#include <sstream>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string res;
        std::stringstream ss(s);
        std::string temp;
        while(ss >> temp)
        {
            std::reverse(temp.begin(), temp.end());
            res += temp;
            res += ' ';
        }
        if(res.back() == ' ')
        {
            res.pop_back();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.reverseWords("Let's take LeetCode contest") == 
            "s'teL ekat edoCteeL tsetnoc");
        assert(sol.reverseWords("God Ding") == "doG gniD");

    }
    return 0;
}