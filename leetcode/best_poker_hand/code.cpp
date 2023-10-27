#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::string bestHand(std::vector<int>& ranks, std::vector<std::string>& suits) 
    {
        suits.erase(std::unique(suits.begin(), suits.end()), suits.end());
        if(suits.size() == 1)
        {
            return "Flush";
        }

        std::sort(ranks.begin(), ranks.end());
        int most_of_rank = 1;
        int count_ranks = 1;
        for(int i = 1; i < ranks.size(); i++)
        {
            if(ranks[i] == ranks[i - 1])
            {
                count_ranks++;
            }
            if(ranks[i] != ranks[i - 1])
            {
                if(most_of_rank < count_ranks)
                {
                    most_of_rank = count_ranks;
                }
                count_ranks = 1;
            }
        }
        if(most_of_rank < count_ranks)
        {
            most_of_rank = count_ranks;
        }

        if(most_of_rank >= 3)
        {
            return "Three of a Kind";
        }
        else if(most_of_rank == 2)
        {
            return "Pair";
        }
        return "High Card";
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> ranks = {13,2,3,1,9};
        std::vector<std::string> suits = {"a","a","a","a","a"};
        std::string res = "Flush";
        assert(sol.bestHand(ranks, suits) == res);
    }
    {
        std::vector<int> ranks = {4,4,2,4,4};
        std::vector<std::string> suits = {"d","a","a","b","c"};
        std::string res = "Three of a Kind";
        assert(sol.bestHand(ranks, suits) == res);
    }
    {
        std::vector<int> ranks = {10,10,2,12,9};
        std::vector<std::string> suits = {"a","b","c","a","d"};
        std::string res = "Pair";
        assert(sol.bestHand(ranks, suits) == res);
    }
    return 0;
}