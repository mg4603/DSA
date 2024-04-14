#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, 
                    std::vector<std::vector<int>>& queries) {
        std::ios::sync_with_stdio(0);
        int n = arr.size();
        std::vector<int> preSum(n + 1, 0);
        for(int i = 1; i <= arr.size(); i++)
        {
            preSum[i] = preSum[i - 1] ^ arr[i - 1];
        }
        
        int m = queries.size();
        std::vector<int> res(m); 
        for(int i = 0; i < m; i++)
        {
            int left = queries[i][0];
            int right = queries[i][1] + 1;
            res[i] = preSum[left] ^ preSum[right];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,3,4,8};
        std::vector<std::vector<int>> queries = {{0,1},{1,2},
                                                 {0,3},{3,3}};
        std::vector<int> res = {2,7,14,8};
        assert(sol.xorQueries(arr, queries) == res);
    }
    return 0;
}