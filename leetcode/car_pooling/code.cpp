#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        std::ios::sync_with_stdio(0);
        int n = trips.back().back();
        std::vector<int> passengers(1001, 0);
        for(int i = 0; i < trips.size(); i++)
        {
            int l = trips[i][1];
            int r = trips[i][2];
            int num = trips[i][0];
            passengers[l] += num;
            passengers[r] -= num;
        }

        bool res = true;
        for(int i = 0; i < 1001; i++)
        {
            if(i > 0)passengers[i] += passengers[i - 1];
            if(passengers[i] > capacity)res = false;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> trips = {{2,1,5},{3,3,7}};
        int capacity = 4;
        bool res = false;
        assert(sol.carPooling(trips, capacity) == res);
    }
    return 0;
}