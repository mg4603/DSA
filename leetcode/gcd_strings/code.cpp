#include <iostream>
#include <assert.h>

class Solution {
    int gcd(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        if(str1 + str2 != str2 + str1)
        {
            return "";
        }
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.gcdOfStrings("ABCABC", "ABC") == "ABC");
        assert(sol.gcdOfStrings("ABABAB", "ABAB") == "AB");
        assert(sol.gcdOfStrings("LEET", "CODE") == "");
    }
    return 0;
}