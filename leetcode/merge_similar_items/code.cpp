#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> mergeSimilarItems(
                                    std::vector<std::vector<int>>& items1, 
                                    std::vector<std::vector<int>>& items2) 
    {
        std::sort(items1.begin(), items1.end(), [](auto a, auto b)
        {
            return a[0] < b[0];
        });
        std::sort(items2.begin(), items2.end(), [](auto a, auto b)
        {
            return a[0] < b[0];
        });

        int i = 0;
        int j = 0;
        std::vector<std::vector<int>> res;
        while(i < items1.size() && j < items2.size())
        {
            if(items1[i][0] < items2[j][0])
            {
                res.push_back(items1[i++]);
            }
            else if(items1[i][0] > items2[j][0])
            {
                res.push_back(items2[j++]);
            }
            else
            {
                items1[i][1] += items2[j++][1];
                res.push_back(items1[i++]);
            }
        }
        while(i < items1.size())
        {
            res.push_back(items1[i++]);
        }
        while(j < items2.size())
        {
            res.push_back(items2[j++]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> items1 = {
            {1,1},{4,5},{3,8}};
        std::vector<std::vector<int>> items2 = {
            {3,1},{1,5}};
        std::vector<std::vector<int>> res = {
            {1,6},{3,9},{4,5}};
        assert(sol.mergeSimilarItems(items1, items2) == res);
    }
    {
        std::vector<std::vector<int>> items1 = {
            {1,1},{3,2},{2,3}};
        std::vector<std::vector<int>> items2 = {
            {2,1},{3,2},{1,3}};
        std::vector<std::vector<int>> res = {
            {1,4},{2,4},{3,4}};
        assert(sol.mergeSimilarItems(items1, items2) == res);
    }
    {
        std::vector<std::vector<int>> items1 = {
            {1,3},{2,2}};
        std::vector<std::vector<int>> items2 = {
            {7,1},{2,2},{1,4}};
        std::vector<std::vector<int>> res = {
            {1,7},{2,4},{7,1}};
        assert(sol.mergeSimilarItems(items1, items2) == res);
    }
    return 0;
}