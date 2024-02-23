#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxRepOpt1(std::string text) {
        std::vector<std::vector<int>> pos(26);
        int res = 0;
        int n = text.length();

        for(int i = 0; i < n; i++)pos[text[i] - 'a'].push_back(i);

        for(int i = 0; i < 26; i++)
        {
            int cnt = 1;
            int cnt1 = 0;
            int maxLen = 0;
            for(int j = 1; j < pos[i].size(); j++)
            {
                if(pos[i][j] == pos[i][j - 1] + 1)
                {
                    cnt++;
                }
                else
                {
                    cnt1 = (pos[i][j] == pos[i][j - 1] + 2) ? cnt: 0;
                    cnt = 1;
                }
                maxLen = std::max(maxLen, cnt + cnt1);
            }
            res = std::max(res, maxLen + ((pos[i].size() > maxLen) ? 1 : 0));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string text = "ababa";
        int res = 3;
        assert(sol.maxRepOpt1(text) == res);
    }
    return 0;
}