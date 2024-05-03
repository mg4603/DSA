#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::vector<int>> groupThePeople(
                            std::vector<int>& groupSizes) {
        std::map<int, std::vector<int>> mp;
        int n = groupSizes.size();
        for(int i = 0; i < n; i++){
            mp[groupSizes[i]].push_back(i);
        }

        std::vector<std::vector<int>> res;
        for(auto [size, vec]: mp){
            std::vector<int> temp;
            for(int num: vec){
                temp.push_back(num);
                if(temp.size() == size){
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> groupSizes = {3,3,3,3,3,1,3};
        std::vector<std::vector<int>> res = {{5},{0,1,2}, 
                                             {3,4,6}};

        assert(sol.groupThePeople(groupSizes) == res);
    }
    return 0;
}