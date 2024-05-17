#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> restoreArray(
                std::vector<std::vector<int>> &adjacentPairs) {
        std::unordered_map<int, std::vector<int>> mp;

        int start;
        for(auto &it: adjacentPairs) {
            if(!mp.count(it[0])) {
                mp[it[0]].push_back(0);
            }
            if(!mp.count(it[1])) {
                mp[it[1]].push_back(0);
            }
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        for(auto &it: mp) {
            if(it.second.size() == 2) {
                start = it.first;
                break;
            }
        }
        
        std::vector<int> res;
        res.push_back(start);
        mp[start][0] = 1;
        while(res.size() != adjacentPairs.size() + 1) {
            for(int i = 1; i < mp[res.back()].size(); i++) {
                if(mp[mp[res.back()][i]][0] == 1)continue;
                mp[mp[res.back()][i]][0] = 1;
                res.push_back(mp[res.back()][i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> adjacentPairs = {
                    {2,1},{3,4},{3,2}};
        std::vector<int> res {4,3,2,1};
        assert(sol.restoreArray(adjacentPairs) == res);
    }
    return 0;
}