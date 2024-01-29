#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string pushDominoes(std::string s) {
        int n = s.length();
        int right = -1;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'L')
            {
                if(right == -1)
                {
                    for(int j = i - 1; j >= 0 && s[j] == '.'; j--)
                    {
                        s[j] = 'L';
                    }
                }
                else
                {
                    for(int j = right + 1, k = i - 1; j < k; j++, k--)
                    {
                        s[j] = 'R';
                        s[k] = 'L';
                    }
                    right = -1;
                }
            }
            else if(s[i] == 'R')
            {
                if(right != -1)
                {
                    for(int j = right + 1; j < i; j++)
                    {
                        s[j] = 'R';
                    }
                }
                right = i;
            }
        }
        if(right != -1)
        {
            for(int i = right + 1; i < n; i++)
            {
                s[i] = 'R';
            }
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string dominoes = "RR.L";
        std::string res = "RR.L";
        assert(sol.pushDominoes(dominoes) == res);
    }
    return 0;
}