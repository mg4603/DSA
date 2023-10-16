#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        std::ios_base::sync_with_stdio(0);
        std::map<int, int> fq;
        for(int i = 0; i < arr.size(); i++)
        {
            fq[arr[i]]++;
        }

        int res = -1;
        for(auto pr: fq)
        {
            if(pr.first == pr.second)
            {
                res = pr.first;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,2,3,4};
        int res = 2;
        assert(sol.findLucky(arr) == res);
    }
    {
        std::vector<int> arr = {1,2,2,3,3,3};
        int res = 3;
        assert(sol.findLucky(arr) == res);
    }
    {
        std::vector<int> arr = {2,2,2,3,3};
        int res = -1;
        assert(sol.findLucky(arr) == res);
    }
    return 0;
}