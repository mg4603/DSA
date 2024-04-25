#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int n;
    int m;
    int threshold;
    bool doesSquareExist(std::vector<std::vector<int>> &prefix, int len)
    {
        for(int i = len; i <= n; i++)
        {
            for(int j = len; j <= m; j++)
            {
                int sum = prefix[i][j] - prefix[i - len][j] - 
                            prefix[i][j - len] + prefix[i - len][j - len];
                if(sum <= threshold)return true;
            }
        }
        return false;
    }
public:
    int maxSideLength(std::vector<std::vector<int>>& mat, 
                        int threshold) {
        std::ios::sync_with_stdio(0);
        n = mat.size();
        m = mat[0].size();
        this->threshold = threshold;
        int res = 0;
        std::vector<std::vector<int>> prefix(n + 1, 
                            std::vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                prefix[i][j] -= prefix[i - 1][j - 1];
                prefix[i][j] += prefix[i - 1][j];
                prefix[i][j] += prefix[i][j - 1];
                prefix[i][j] += mat[i - 1][j - 1];
            }
        }

        int l = 0;
        int h = std::min(n, m);
        while(l <= h)
        {
            int mid = (l + h) / 2;
            if(doesSquareExist(prefix, mid))
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return h;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> mat = {{1,1,3,2,4,3,2},
                                             {1,1,3,2,4,3,2},
                                             {1,1,3,2,4,3,2}};
        int threshold = 4;
        int res = 2;
        assert(sol.maxSideLength(mat, threshold) == res);
    }
    return 0;
}