#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> circularPermutation(int n, int start) {
        std::vector<int> arr;
        for(int i = 0; i < 1 << n; i++) {
            arr.push_back(start ^ i ^ (i >> 1));
        }
        return arr;
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        int start = 3;
        std::vector<int> res = {3, 2, 0, 1};
        assert(sol.circularPermutation(n, start) == res);
    }
    return 0;
}