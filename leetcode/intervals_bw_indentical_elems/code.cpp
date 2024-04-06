#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <numeric>

class Solution {
public:
    std::vector<long long> getDistances(std::vector<int>& arr) {
        std::ios::sync_with_stdio(0);
        int n = arr.size();
        std::unordered_map<int, std::vector<int>> mp;
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }

        std::vector<long long> res(n, 0LL);
        for(auto &it: mp)
        {
            std::vector<int> indices = it.second;

            long long prefix = 0LL;
            long long postfix = std::accumulate(indices.begin(), 
                                    indices.end(), 0LL);

            int m = indices.size();
            for(int i = 0; i < m; i++)
            {
                prefix += indices[i];
                postfix -= indices[i];
                int index = indices[i];
                res[index] += 1LL * index * (i + 1);
                res[index] -= prefix;
                res[index] += postfix;
                res[index] -= 1LL * (m - i - 1) * index;
            }

        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,1,3,1,2,3,3};
        std::vector<long long> res = {4,2,7,2,4,4,5};

        assert(sol.getDistances(arr) == res);
    }
    return 0;
}