#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

class Solution {
public:
    int minStoneSum(std::vector<int>& piles, int k) {
        std::ios::sync_with_stdio(0);
        std::priority_queue<int> pq(piles.begin(), piles.end());
        while(k--) {
            int temp = pq.top();
            pq.pop();
            temp -= (temp / 2);
            pq.push(temp);
        }
        int res = 0;
        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> piles = {5,4,9};
        int k = 2, res = 12;
        assert(sol.minStoneSum(piles, k) == res);
    }
    return 0;
}