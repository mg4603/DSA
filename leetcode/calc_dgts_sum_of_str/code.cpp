#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string digitSum(std::string s, int k) 
    {
        while(s.length() > k)
        {
            std::string str;
            for(int i = 0; i < s.length(); i += k)
            {
                int temp = 0;
                for(int j = 0; j < k; j++)
                {
                    if(i + j >= s.length())break;
                    temp += (s[i + j] - '0');
                }
                str += std::to_string(temp);
            }
            s = str;
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "11111222223";
        int k = 3;
        std::string res = "135";
        assert(sol.digitSum(s, k) == res);
    }
    {
        std::string s = "00000000";
        int k = 3;
        std::string res = "000";
        assert(sol.digitSum(s, k) == res);
    }
    return 0;
}