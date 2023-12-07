#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue(
                        std::vector<std::vector<int>>& people) 
    {
        std::sort(people.begin(), people.end(), 
                    [](std::vector<int> a, std::vector<int> b)
        {
            if(a[0] == b[0])            
            {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });  

        std::vector<std::vector<int>> res;
        res.push_back(people[0]);

        for(int i = 1; i < people.size(); i++)
        {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> people = 
                        {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
        std::vector<std::vector<int>> res = 
                        {{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}};
        assert(sol.reconstructQueue(people) == res);

    }
    {
        std::vector<std::vector<int>> people = 
                        {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
        std::vector<std::vector<int>> res = 
                        {{4,0},{5,0},{2,2},{3,2},{1,4},{6,0}};
        assert(sol.reconstructQueue(people) == res);

    }
    return 0;
}