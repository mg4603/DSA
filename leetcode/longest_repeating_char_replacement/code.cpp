#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int characterReplacement(std::string s, int k) 
    {
        int n = s.length();

        int l = 0;
        int r = 0;

        int max_f = 0;
        std::vector<int> freq(26, 0);
        int res = 0;

        for(int r = 0; r < n; r++)
        {
            int temp = ++freq[s[r] - 'A'];

            if(temp > max_f)
            {
                max_f = temp;
            }


            if((r - l + 1) - max_f > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }   

            if((r - l + 1) > res)
            {
                res = (r - l + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "ABAB";
        int k = 2;
        int res = 4;
        assert(sol.characterReplacement(s, k) == res);
    }
    {
        std::string s = "AABABBA";
        int k = 1;
        int res = 4;
        assert(sol.characterReplacement(s, k) == res);
    }
    return 0;
}