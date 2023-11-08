#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int getWinner(std::vector<int>& arr, int k) 
    {
        int n = arr.size();
        int cnt = 0;

        int i = 0;
        int j = 1;

        while(i < n && j < n)
        {
            if(arr[i] > arr[j])
            {
                j++;
                cnt++;
                if(cnt >= k)
                {
                    return arr[i];
                }
            }
            else
            {
                i = j;
                j = i + 1;
                cnt = 1;
                if(cnt >= k)
                {
                    return arr[i];
                }
            }
        }
        return arr[i];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,1,3,5,4,6,7};
        int k = 2;
        int res = 5;
        assert(sol.getWinner(arr, k) == res);
    }
    {
        std::vector<int> arr = {3,2,1};
        int k = 10;
        int res = 3;
        assert(sol.getWinner(arr, k) == res);
    }
    return 0;
}