#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) 
    {
        std::vector<double> time;

        for(int i = 0; i < dist.size(); i++)
        {
            time.push_back(dist[i] / static_cast<double>(speed[i]));
        }

        std::sort(time.begin(), time.end());

        int t = 0;
        int res = 1;
        
        for(int i = 1; i < dist.size(); i++)
        {
            t++;
            if(time[i] <= t)
            {
                break;
            }
            res++;
        }
        return res;
    }
};


int main()
{
    Solution sol;
    {
        std::vector<int> dist = {1,3,4};
        std::vector<int> speed = {1,1,1};
        int res = 3;
        assert(sol.eliminateMaximum(dist, speed) == res);
    }
    {
        std::vector<int> dist = {1,1,2,3};
        std::vector<int> speed = {1,1,1,1};
        int res = 1;
        assert(sol.eliminateMaximum(dist, speed) == res);
    }
    {
        std::vector<int> dist = {3,2,4};
        std::vector<int> speed = {5,3,2};
        int res = 1;
        assert(sol.eliminateMaximum(dist, speed) == res);
    }
    return 0;
}