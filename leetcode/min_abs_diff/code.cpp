#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        std::ios_base::sync_with_stdio(0);
        
        std::sort(arr.begin(), arr.end());
        int min_diff = std::numeric_limits<int>::max();
        std::vector<std::vector<int>> res;

        for(int i = 1; i < arr.size(); i++)
        {
            int temp = arr[i] - arr[i - 1];
            if(temp < min_diff)
            {
                min_diff = temp;
                res.clear();
                
            }
            if(temp == min_diff)
            {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {4,2,1,3};
        std::vector<std::vector<int>> res = {
            {1,2},{2,3},{3,4}
        };
        assert(sol.minimumAbsDifference(arr) == res);
    }
    {
        std::vector<int> arr = {1,3,6,10,15};
        std::vector<std::vector<int>> res = {
            {1,3}
        };
        assert(sol.minimumAbsDifference(arr) == res);
    }
    {
        std::vector<int> arr = {3,8,-10,23,19,-4,-14,27};
        std::vector<std::vector<int>> res = {
           {-14,-10}, {19,23}, {23,27}
        };
        assert(sol.minimumAbsDifference(arr) == res);
    }
    return 0;
}