#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int minimumCost(int m, int n, 
            std::vector<int>& horizontalCut, 
            std::vector<int>& verticalCut) {

        std::ios::sync_with_stdio(0);
        int res = std::accumulate(horizontalCut.begin(), 
                        horizontalCut.end(), 0) +
            std::accumulate(verticalCut.begin(), 
                    verticalCut.end(), 0);
        
        for(int i = 0; i < horizontalCut.size(); i++) {
            for(int j = 0; j < verticalCut.size(); j++) {
                res += std::min(horizontalCut[i], 
                            verticalCut[j]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int m = 3, n = 2;
        std::vector<int> horizontalCut = {1,3};
        std::vector<int> verticalCut = {5};
        int res = 13;
        assert(sol.minimumCost(m, n, horizontalCut, 
                    verticalCut) == res);
    }
    return 0;
}