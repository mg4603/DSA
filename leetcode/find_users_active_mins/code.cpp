#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findingUsersActiveMinutes(
                    std::vector<std::vector<int>>& logs, int k) {
        std::ios::sync_with_stdio(0);
        // id - uam
        std::unordered_map<int, std::unordered_set<int>> mp;
        for(auto &log: logs) {
            mp[log[0]].insert(log[1]);
        }

        std::vector<int> res(k);
        for(auto &it: mp) {
            res[it.second.size() - 1]++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> logs = {{0,5},{1,2},
                                 {0,2},{0,5},{1,3}};
        int k = 5;
        std::vector<int> res = {0,2,0,0,0};
        assert(sol.findingUsersActiveMinutes(logs, k) == res);
    }
    return 0;
}