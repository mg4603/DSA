#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded, int first) 
    {
        std::ios_base::sync_with_stdio(0);
        int n = encoded.size() + 1;
        std::vector<int> res(n, 0);
        res[0] = first;
        for(int i = 0; i < encoded.size(); i++)
        {
            res[i + 1] = res[i] ^ encoded[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> encoded = {1,2,3};
        std::vector<int> res = {1,0,2,1};
        int first = 1;
        assert(sol.decode(encoded, first) == res);
    }
    {
        std::vector<int> encoded = {6,2,7,3};
        std::vector<int> res = {4,2,0,7,4};
        int first = 4;
        assert(sol.decode(encoded, first) == res);
    }
    return 0;
}