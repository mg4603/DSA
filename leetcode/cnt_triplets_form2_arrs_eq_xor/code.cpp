#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int sum = arr[i];
            for(int j = i + 1; j < n; j++)
            {
                sum ^= arr[j];
                if(sum == 0){
                    res += (j - i);
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
        std::vector<int> arr = {2,3,1,6,7};
        int res = 4;
        assert(sol.countTriplets(arr) == res);
    }
    return 0;
}