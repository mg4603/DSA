#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    bool canFormArray(std::vector<int>& arr, 
                        std::vector<std::vector<int>>& pieces) 
    {
        std::vector<int> vec(101, 0);
        for(int i = 0; i < arr.size(); i++)
        {
            vec[arr[i]]++;
        }

        for(int i = 0; i < pieces.size(); i++)
        {
            if(pieces[i].size() == 1 && vec[pieces[i][0]] > 0)
            {
                vec[pieces[i][0]]--;
                continue;
            }
            else
            {
                int k = std::find(arr.begin(), arr.end(), 
                                    pieces[i][0]) - arr.begin();
                for(int j = 0; j < pieces[i].size(); j++)
                {
                    if(k >= arr.size() || arr[k++] != pieces[i][j])
                    {
                        return false;
                    }
                    vec[pieces[i][j]]--;
                }
            }
        }
        return std::accumulate(vec.begin(), vec.end(), 0) == 0;
    }   
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {15,88};
        std::vector<std::vector<int>> pieces = {{88},{15}};
        bool res = true;
        assert(sol.canFormArray(arr, pieces) == res);
    }
    {
        std::vector<int> arr = {49,18,16};
        std::vector<std::vector<int>> pieces = {{16,18,49}};
        bool res = false;
        assert(sol.canFormArray(arr, pieces) == res);
    }
    {
        std::vector<int> arr = {91,4,64,78};
        std::vector<std::vector<int>> pieces = {{78},{4,64},{91}};
        bool res = true;
        assert(sol.canFormArray(arr, pieces) == res);
    }
    return 0;
}