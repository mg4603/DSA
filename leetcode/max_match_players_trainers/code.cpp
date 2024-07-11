#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int matchPlayersAndTrainers(std::vector<int>& players, 
                        std::vector<int>& trainers) {
        std::ios::sync_with_stdio(0);
        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());

        int res = 0;
        int i = players.size() - 1;
        int j = trainers.size() - 1;
        while(i >= 0 && j >= 0) {
            while(i >= 0 && j >= 0 && 
                players[i] > trainers[j])i--;
            while(i >= 0 && j >= 0 && 
                players[i] <= trainers[j]) {
                res++;
                i--;
                j--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> players = {4,7,9};
        std::vector<int> trainers = {8,2,5,8};
        int res = 2;
        assert(sol.matchPlayersAndTrainers(players, trainers) == res);
    }
    return 0;
}