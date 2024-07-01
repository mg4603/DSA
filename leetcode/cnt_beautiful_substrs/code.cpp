#include <iostream>
#include <assert.h>

class Solution {
public:
    int beautifulSubstrings(std::string s, int k) {
        int n = s.length();
        
        std::string vowels = "aeiou";
        int res = 0;

        for(int i = 0; i < n; i++)
        {
            int c = 0; 
            int v = 0;
            for(int j = i; j < n; j++)
            {
                if(vowels.find(s[j]) != std::string::npos)v++;
                else c++;
                if(c == v && (c * v) % k == 0)res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "baeyh";
        int k = 2;
        int res = 2;
        assert(sol.beautifulSubstrings(s, k) == res);
    }
    return 0;
}