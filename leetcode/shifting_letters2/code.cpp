#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string shiftingLetters(std::string s, 
                    std::vector<std::vector<int>>& shifts) {

        int n = s.length();
        std::vector<int> sz(n + 1, 0);
        for(int i = 0; i < shifts.size(); i++)
        {
            if(shifts[i][2] == 1)
            {
                sz[shifts[i][0]]++;
                sz[shifts[i][1] + 1]--;
            }
            else
            {
                sz[shifts[i][0]]--;
                sz[shifts[i][1] + 1]++;
            }
        }

        for(int i = 1; i < n + 1; i++)
        {
            sz[i] += sz[i - 1];
        }

        for(int i = 0; i < n; i++)
        {
            int temp = (s[i] - 'a' + sz[i]) % 26;
            temp = (temp + 26) % 26;
            s[i] = temp + 'a';
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abc";
        std::vector<std::vector<int>> shifts = {{0,1,0},
                                                {1,2,1},
                                                {0,2,1}};
        std::string res = "ace";
        assert(sol.shiftingLetters(s, shifts) == res);
    }
    return 0;
}