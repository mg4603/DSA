#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> shortestToChar(std::string s, char c) {
        std::vector<int> pos;
        int i(0);
        for(char ch: s)
        {
            if(ch == c)
            {
                pos.push_back(i);
            }
            i++;
        }

        std::vector<int> res;
        int j(0);
        for(i = 0; i < s.size(); i++)
        {
            if(j + 1 < pos.size())
            {
                int temp1 = std::abs(i - pos[j]);
                int temp2 = std::abs(i - pos[j + 1]);
                if(temp2 < temp1)
                {
                    j++;
                    res.push_back(temp2);
                }
                else
                {
                    res.push_back(temp1);
                }
            }
            else
            {
                res.push_back(std::abs(i - pos[j]));
            }
            

            
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "loveleetcode";
        char ch = 'e';
        std::vector<int> res = {3,2,1,0,1,0,0,1,2,2,1,0};
        assert(sol.shortestToChar(s, ch) == res);
    }
    {
        std::string s = "aaab";
        char ch = 'b';
        std::vector<int> res = {3,2,1,0};
        assert(sol.shortestToChar(s, ch) == res);
    }
    return 0;
}