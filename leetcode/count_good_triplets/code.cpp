#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int arr_i = arr[i];
            for(int j = i + 1; j < n; j++)
            {
                int arr_j = arr[j];
                int diff_a = std::abs(arr_i - arr_j);
                if(diff_a > a)
                {
                    continue;
                }
                for(int k = j + 1; k < n; k++)
                {
                    int arr_k = arr[k];
                    int diff_b = std::abs(arr_j - arr_k);
                    int diff_c = std::abs(arr_k - arr_i);
                    if(diff_b > b || diff_c > c)
                    {
                        continue;
                    }
                    res++;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {3,0,1,1,9,7};
        int a = 7;
        int b = 2;
        int c = 3;
        int res = 4;
        assert(sol.countGoodTriplets(arr, a, b, c) == res);
    }
    {
        std::vector<int> arr = {1,1,2,2,3};
        int a = 0;
        int b = 0;
        int c = 1;
        int res = 0;
        assert(sol.countGoodTriplets(arr, a, b, c) == res);
    }
    return 0;
}