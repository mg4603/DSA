#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
    int mod = 1e9 + 7;
public:
    int numFactoredBinaryTrees(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());

        std::unordered_map<int, long> table;
        int res = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            table[arr[i]] = 1;
            for(int j = 0; j < i; j++)
            {
                if(arr[i] % arr[j] != 0)continue;
                table[arr[i]] = ((table[arr[i]] % mod) + 
                                 (((table[arr[j]] % mod) * 
                                  ((table[arr[i] / arr[j]]) % mod)) 
                                  % mod)) % mod;
            }
            res = ((res % mod) + (table[arr[i]] % mod)) % mod;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,4};
        int res = 3;
        assert(sol.numFactoredBinaryTrees(arr) == res);
    }
    return 0;
}