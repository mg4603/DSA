#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> mostVisited(int n, std::vector<int>& rounds) 
    {
        std::vector<int> vec(n + 1, 0);
        for(int i = 0; i < rounds.size() - 1; i++)
        {
            for(int j = rounds[i]; j != rounds[i + 1]; j++)
            {
                vec[j]++;
                j %= n;
            }
        }
        vec[rounds.back()]++;

        std::vector<int> res;
        int max_round = 0;
        for(int i = 0; i < n + 1; i++)
        {
            if(vec[i] > max_round)
            {
                res.clear();
                max_round = vec[i];
                res.push_back(i);
            }
            else if(vec[i] == max_round)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 4;
        std::vector<int> rounds = {1,3,1,2};
        std::vector<int> res = {1, 2};
        assert(sol.mostVisited(n, rounds) == res);
    }
    {
        int n = 2;
        std::vector<int> rounds = {2,1,2,1,2,1,2,1,2};
        std::vector<int> res = {2};
        assert(sol.mostVisited(n, rounds) == res);
    }
    {
        int n = 7;
        std::vector<int> rounds = {1,3,5,7};
        std::vector<int> res = {1,2,3,4,5,6,7};
        assert(sol.mostVisited(n, rounds) == res);
    }
    return 0;
}