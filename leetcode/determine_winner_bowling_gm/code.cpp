#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int isWinner(std::vector<int>& player1, std::vector<int>& player2) 
    {
        int n = player1.size();
        int player1_score = 0;
        int player2_score = 0;

        for(int i = 0; i < n; i++)
        {
            if(i - 2 >= 0 && player1[i - 2] == 10)
            {
                player1_score += (2 * player1[i]);
            }
            else if(i - 1 >= 0 && player1[i - 1] == 10)
            {
                player1_score += (2 * player1[i]);
            }
            else
            {
                player1_score += player1[i];
            }

            if(i - 2 >= 0 && player2[i - 2] == 10)
            {
                player2_score += (2 * player2[i]);
            }
            else if(i - 1 >= 0 && player2[i - 1] == 10)
            {
                player2_score += (2 * player2[i]);
            }
            else
            {
                player2_score += player2[i];
            }
        }

        if(player1_score > player2_score)
        {
            return 1;
        }
        else if(player2_score > player1_score)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> player1 = {4,10,7,9};
        std::vector<int> player2 = {6,5,2,3};
        int res = 1;
        assert(sol.isWinner(player1, player2) == res);
    }
    {
        std::vector<int> player1 = {3,5,7,6};
        std::vector<int> player2 = {8,10,10,2};
        int res = 2;
        assert(sol.isWinner(player1, player2) == res);
    }
    {
        std::vector<int> player1 = {2,3};
        std::vector<int> player2 = {4,1};
        int res = 0;
        assert(sol.isWinner(player1, player2) == res);
    }
    return 0;
}