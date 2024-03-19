#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        int n = s.length();
        int ones = 0;

        int j = 0;
        int len = n;;
        std::string res = "";
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')ones++;

            while(ones > k)
            {
                if(s[j] == '1')ones--;
                j++;
            }
            while(s[j] == '0')j++;

            if(ones == k)
            {
                if(i - j + 1 < len)
                {
                    len = i - j + 1;
                    res = s.substr(j, len);
                }
                else if(i - j + 1 == len)
                {
                    std::string temp = s.substr(j, i - j + 1);
                    if(temp < res)
                    {
                        res = temp;
                    }
                }
            }
        }
        if(ones == k && j == 0 && res == "")
        {
            return s;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "100011001";
        int k = 3;
        std::string res = "11001";
        assert(sol.shortestBeautifulSubstring(s, k) == res);
    }
    return 0;
}