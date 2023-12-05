#include <iostream>
#include <assert.h>

#include <queue>
#include <vector>

class Solution {
public:
    bool canMeasureWater(int j1, int j2, int targetCapacity) 
    {
        int j = j1 + j2;

        std::vector<int> options = {j1, -j1, j2, -j2};
        std::vector<int> possible_caps(j + 1, 0);

        std::queue<int> q;
        q.push(0);
        possible_caps[0] = 1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(node == targetCapacity)
            {
                return true;
            }
            else
            {
                for(int i = 0; i < 4; i++)
                {
                    int temp = node + options[i];
                    if(temp >= 0 && temp <= j && 
                        possible_caps[temp] == 0)
                    {
                        possible_caps[temp] = 1;
                        q.push(temp);
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        int jug1Capacity = 3;
        int jug2Capacity = 5;
        int targetCapacity = 4;
        bool res = true;
        assert(
            sol.canMeasureWater(jug1Capacity, 
                                jug2Capacity, 
                                targetCapacity) == res);
    }
    {
        int jug1Capacity = 2;
        int jug2Capacity = 6;
        int targetCapacity = 5;
        bool res = false;
        assert(
            sol.canMeasureWater(jug1Capacity, 
                                jug2Capacity, 
                                targetCapacity) == res);
    }
    {
        int jug1Capacity = 1;
        int jug2Capacity = 2;
        int targetCapacity = 3;
        bool res = true;
        assert(
            sol.canMeasureWater(jug1Capacity, 
                                jug2Capacity, 
                                targetCapacity) == res);
    }
    return 0;
}