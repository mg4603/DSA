#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findTheWinner(int n, int k) {
        std::ios::sync_with_stdio(0);
        std::vector<int> vec;
        for(int i = 1; i <= n; i++)vec.push_back(i);
        
        int pos = (k - 1) % n;

        while(n > 1) {
            vec.erase(vec.begin() + pos);
            n = vec.size();
            pos = (pos + k - 1) % n;
        }
        return vec[0];
    }
};

int main()
{
    Solution sol;
    {
        int n = 5;
        int k = 2;
        int res = 3;
        assert(sol.findTheWinner(n, k) == res);
    }
    return 0;
}