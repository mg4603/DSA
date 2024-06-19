#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool solve(std::vector<int> &arr, int i, 
                std::vector<int> &visited) {
        if(i < 0 || i >= arr.size() || 
            visited[i])return false;
        if(arr[i] == 0)return true;
        visited[i] = 1;
        return solve(arr, i + arr[i], visited) || 
                solve(arr, i - arr[i], visited);
    }
public:
    bool canReach(std::vector<int>& arr, int start) {
        std::ios::sync_with_stdio(0);
        if(arr[start] == 0)return true;
        std::vector<int> visited(arr.size(), 0);
        visited[start] = 1;
        return solve(arr, start - arr[start], visited) ||
            solve(arr, start + arr[start], visited);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {4,2,3,0,3,1,2};
        int start = 5;
        bool res = true;
        assert(sol.canReach(arr, start) == res);
    }
    {
        std::vector<int> arr = {4,2,3,0,3,1,2};
        int start = 0;
        bool res = true;
        assert(sol.canReach(arr, start) == res);
    }
    {
        std::vector<int> arr = {3,0,2,1,2};
        int start = 2;
        bool res = false;
        assert(sol.canReach(arr, start) == res);
    }
    return 0;
}