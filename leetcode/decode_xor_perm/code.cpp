#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded) {
        std::ios::sync_with_stdio(0);
        int p0 = 0;
        int n = encoded.size();
        for(int i = 1; i <= n + 1; i++) {
            p0 ^= i;
        }

        for(int i = 1; i < n; i += 2) {
            p0 ^= encoded[i];
        }

        std::vector<int> res(n + 1);
        res[0] = p0;
        for(int i = 0; i < n; i++) {
            res[i + 1] = res[i] ^ encoded[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> encoded = {3,1};
        std::vector<int> res = {1, 2, 3};
        assert(sol.decode(encoded) == res);
    }
    return 0;
}