#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, 
                            std::vector<int>& arr2, int d) {
        std::ios_base::sync_with_stdio(0);
        int res = 0;
        for(auto it1: arr1)
        {
            int flag = 1;
            for(auto it2: arr2)
            {
                if(std::abs(it1 - it2) <= d)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
            {
                res++;
            }
            
        }   
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr1 = {4,5,8};
        std::vector<int> arr2 = {10,9,1,8};
        int d = 2;
        int res = 2;
        assert(sol.findTheDistanceValue(arr1, arr2, d) == res);
    }
    {
        std::vector<int> arr1 = {1,4,2,3};
        std::vector<int> arr2 = {-4,-3,6,10,20,30};
        int d = 3;
        int res = 2;
        assert(sol.findTheDistanceValue(arr1, arr2, d) == res);
    }
    {
        std::vector<int> arr1 = {2,1,100,3};
        std::vector<int> arr2 = {-5,-2,10,-3,7};
        int d = 6;
        int res = 1;
        assert(sol.findTheDistanceValue(arr1, arr2, d) == res);
    }
    return 0;
}