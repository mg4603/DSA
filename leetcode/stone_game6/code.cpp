#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int stoneGameVI(std::vector<int>& A, std::vector<int>& B) {
        std::ios::sync_with_stdio(0);
        int n = A.size();
        int alice = 0;
        for(int i = 0; i < n; i++) {
            A[i] += B[i];
            alice -= B[i];
        }     

        std::sort(A.begin(), A.end());

        int i = n - 1;
        for(; i >= 0; i -= 2) {
            alice += A[i];
        }

        if(alice > 0) return 1;
        else if(alice < 0)return -1;
        return 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> aliceValues = {1,3};
        std::vector<int> bobValues = {2,1};
        int res = 1;
        assert(sol.stoneGameVI(aliceValues, bobValues) == res);
    }
    return 0;
}