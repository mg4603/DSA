#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int lenLongestFibSubseq(std::vector<int>& arr) {
        int n = arr.size();

        std::unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]] = i;
        }

        std::vector<std::vector<int>> table(n, 
                        std::vector<int>(n, 2));
        int res = 2;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int x = arr[i] - arr[j];
                if(mp.find(x) != mp.end() && mp[x] < j)
                {
                    table[j][i] = std::max(table[j][i], 
                                    table[mp[x]][j] + 1);
                }
                res = std::max(res, table[j][i]);
            }
        }
        return res > 2 ? res : 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,2,3,4,5,6,7,8};
        int res = 5;
        assert(sol.lenLongestFibSubseq(arr) == res);
    }
    return 0;
}