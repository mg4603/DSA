#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool helper(std::vector<int> &freq)
    {
        for(int f: freq)
        {
            if(f > 0)return false;
        }
        return true;
    }

    int charToIdx(char ch)
    {
        switch(ch)
        {
            case 'Q':
                return 0;
            case 'W':
                return 1;
            case 'E':
                return 2;
        }
        return 3;
    }
public:
    int balancedString(std::string s) {
        int n = s.length();
        std::vector<int> freq(4, 0);

        for(int i = 0; i < n; i++)
        {
            freq[charToIdx(s[i])]++;
        }
        int req = n / 4;

        int cnt = 0;
        for(int i = 0; i < 4; i++)
        {
            if(freq[i] == req)cnt++;
            freq[i] = std::max(0, freq[i] - req);
        }

        if(cnt == 4)return 0;

        int res = n;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            freq[charToIdx(s[i])]--;
            while(helper(freq))
            {
                res = std::min(res, i - j + 1);
                freq[charToIdx(s[j])]++;
                j++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "QWER";
        int res = 0;
        assert(sol.balancedString(s) == res);
    }
    return 0;
}