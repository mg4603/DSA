#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, 
                                            std::vector<int>& B) {
        std::ios::sync_with_stdio(0);
        int n = A.size();
        int cnt = 0;
        std::vector<int> res(n);
        std::vector<int> freq(n + 1);

        for(int i = 0; i < n; i++)
        {
            if(++freq[A[i]] == 2)cnt++;
            if(++freq[B[i]] == 2)cnt++;
            res[i] = cnt;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> A = {1,3,2,4};
        std::vector<int> B = {3,1,2,4};
        std::vector<int> res = {0,2,3,4};
        assert(sol.findThePrefixCommonArray(A, B) == res);
    }
    return 0;
}