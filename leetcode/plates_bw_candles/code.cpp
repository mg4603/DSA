#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> platesBetweenCandles(std::string s, 
                        std::vector<std::vector<int>>& queries) {

        int n = s.length();
        std::vector<int> candles;
        std::vector<int> prefix(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '|')candles.push_back(i);
            else if(s[i] == '*')prefix[i]++;

            if(i > 0)prefix[i] += prefix[i - 1];
        }

        int m = queries.size();
        std::vector<int> res(m, 0);
        for(int i = 0; i < m; i++)
        {
            int l = std::lower_bound(candles.begin(), 
                        candles.end(), queries[i][0]) - candles.begin();
            int r = std::upper_bound(candles.begin(), 
                        candles.end(), queries[i][1]) - candles.begin() - 1;
            if(l > r)continue;
            res[i] = prefix[candles[r]] - prefix[candles[l]];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "**|**|***|";
        std::vector<std::vector<int>> queries = {{2,5},{5,9}};
        std::vector<int> res = {2, 3};
        assert(sol.platesBetweenCandles(s, queries) == res);
    }
    return 0;
}