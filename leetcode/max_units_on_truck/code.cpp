#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) 
    {
        std::ios_base::sync_with_stdio(0);
        std::sort(boxTypes.begin(), boxTypes.end(), 
                    [](const std::vector<int> &a, const std::vector<int> &b)
        {
            return a[1] > b[1];
        });
        int res = 0;

        for(int i = 0; i < boxTypes.size(); i++)
        {
            int temp = boxTypes[i][0];
            if(temp < truckSize)
            {
                truckSize -= temp;
                res += temp * boxTypes[i][1];
            }
            else
            {
                res += truckSize * boxTypes[i][1];
                return res;
            }
        
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> boxTypes = {
            {1,3},{2,2},{3,1}};
        int truckSize = 4;
        int res = 8;
        assert(sol.maximumUnits(boxTypes, truckSize) == res);
    }
    {
        std::vector<std::vector<int>> boxTypes = {
            {5,10},{2,5},{4,7},{3,9}};
        int truckSize = 10;
        int res = 91;
        assert(sol.maximumUnits(boxTypes, truckSize) == res);
    }
    return 0;
}