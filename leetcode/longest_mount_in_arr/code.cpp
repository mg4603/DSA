#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int longestMountain(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> up(n, 0);
        std::vector<int> down(n, 0);

        for(int i = n - 2; i >= 0; i--)
        {
            if(arr[i] > arr[i + 1])
            {
                up[i] = up[i + 1] + 1;
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && arr[i] > arr[i - 1])
            {
                down[i] = down[i - 1] + 1;
            }
            int temp = down[i] + up[i] + 1;
            if(up[i] && down[i])
            {
                res = std::max(res, down[i] + up[i] + 1);
            }
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,1,4,7,3,2,5};
        int res = 5;
        assert(sol.longestMountain(arr) == res);
    }
    return 0;
}