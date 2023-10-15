#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>
#include <numeric>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        std::ios_base::sync_with_stdio(0);
        int n = mat.size();
        std::priority_queue<std::pair<int, int>> pq;

        for(int i = 0; i < k; i++)
        {
            int ones = std::accumulate(mat[i].begin(), mat[i].end(), 0);
            pq.emplace(ones, i);
        }

        for(int i = k; i < n; i++)
        {
            int ones = std::accumulate(mat[i].begin(), mat[i].end(), 0);
            if(ones < pq.top().first)
            {
                pq.emplace(ones, i);
                pq.pop();
            }
        }
        std::vector<int> res(k , 0);
        for(int i = k - 1; i >= 0; i--)
        {
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> mat = {
                                             {1,1,0,0,0},
                                             {1,1,1,1,0},
                                             {1,0,0,0,0},
                                             {1,1,0,0,0},
                                             {1,1,1,1,1}};
        int k = 3;
        std::vector<int> res = {2,0,3};
        assert(sol.kWeakestRows(mat, k) == res);
    }
    {
        std::vector<std::vector<int>> mat = {
                                             {1,0,0,0},
                                             {1,1,1,1},
                                             {1,0,0,0},
                                             {1,0,0,0}};
        int k = 2;
        std::vector<int> res = {0, 2};
        assert(sol.kWeakestRows(mat, k) == res);
    }
    
    return 0;
}