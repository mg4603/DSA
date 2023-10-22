#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maximumPopulation(std::vector<std::vector<int>>& logs) 
    {
        std::vector<int> years(101, 0);
        int max_population = 0;
        int res = 0;
        for(int i = 0; i < logs.size(); i++)
        {
            for(int j = logs[i][0]; j < logs[i][1]; j++)
            {
                int temp = ++years[j - 1950];
                if(temp > max_population)
                {
                    max_population = temp;
                    res = j;
                }
                if(temp == max_population)
                {
                    if(j < res)
                    {
                        res = j;
                    }
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
        std::vector<std::vector<int>>  logs = {
            {1993,1999},{2000,2010}};
        int res = 1993;
        assert(sol.maximumPopulation(logs) == res);
    }
    {
        std::vector<std::vector<int>>  logs = {
            {1950,1961},{1960,1971},{1970,1981}};
        int res = 1960;
        assert(sol.maximumPopulation(logs) == res);
    }
    return 0;
}