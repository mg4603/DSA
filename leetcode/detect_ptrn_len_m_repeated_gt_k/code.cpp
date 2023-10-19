#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool containsPattern(std::vector<int>& arr, int m, int k) {
        std::ios_base::sync_with_stdio(0);
        int count = 0;
        for(int i = 0; i < arr.size() - m; i++)
        {
            if(arr[i] == arr[i + m])
            {
                count++;
                if(count == (k - 1) * m)
                {
                    return true;
                }
            }
            else
            {
                count = 0;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,2,4,4,4,4};
        int m = 1;
        int k = 3;
        int res = 1;
        assert(sol.containsPattern(arr, m, k) == res);
    }
    {
        std::vector<int> arr = {1,2,1,2,1,1,1,3};
        int m = 2;
        int k = 2;
        int res = 1;
        assert(sol.containsPattern(arr, m, k) == res);
    }
    {
        std::vector<int> arr = {1,2,1,2,1,3};
        int m = 2;
        int k = 3;
        int res = 0;
        assert(sol.containsPattern(arr, m, k) == res);
    }
    return 0;
}