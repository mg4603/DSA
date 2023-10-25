#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::string> divideString(std::string s, int k, char fill) 
    {
        std::ios_base::sync_with_stdio(0);
        std::vector<std::string> res;
        for(int i = 0; i < s.length(); i += k)
        {
            if(i + k >= s.length())
            {
                std::string temp = s.substr(i);
                temp += std::string(k - temp.length(), fill);
                res.push_back(temp);
                break;
            }
            res.push_back(s.substr(i, k));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abcdefghi";
        int k = 3;
        char fill = 'x';
        std::vector<std::string> res = {"abc","def","ghi"};
        assert(sol.divideString(s, k, fill) == res);
    }
    {
        std::string s = "abcdefghij";
        int k = 3;
        char fill = 'x';
        std::vector<std::string> res = {"abc","def","ghi","jxx"};
        assert(sol.divideString(s, k, fill) == res);
    }
    return 0;
}