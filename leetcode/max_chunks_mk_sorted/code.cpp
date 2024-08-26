#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxChunksToSorted(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> maxi(n);
        int curr = 0;
        for(int i = 0; i < n; i++) {
            curr = std::max(curr, arr[i]);
            maxi[i] = curr;
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            if(maxi[i] == i)res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {4,3,2,1,0};
        int res = 1;
        assert(sol.maxChunksToSorted(arr) == res);
    }
    return 0;
}