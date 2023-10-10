#include <iostream>
#include <assert.h>

#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> q;

        for(int i = 0; i < stones.size(); i++)
        {
            q.push(stones[i]);
        }
        while(q.size() > 1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(std::abs(a - b));
        }
        return q.top();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> stones = {1};
        int res = 1;
        assert(sol.lastStoneWeight(stones) == res);
    }
    {
        std::vector<int> stones = {2,7,4,1,8,1};
        int res = 1;
        assert(sol.lastStoneWeight(stones) == res);
    }
    return 0;
}