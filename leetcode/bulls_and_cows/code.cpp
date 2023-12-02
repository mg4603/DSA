#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string getHint(std::string secret, std::string guess) 
    {
        std::vector<int> guess_digit(10, 0);
        std::vector<int> secret_digit(10, 0);

        int bulls = 0;
        for(int i = 0; i < guess.length(); i++)
        {
            guess_digit[guess[i] - '0']++;
            secret_digit[secret[i] - '0']++;

            if(secret[i] == guess[i])
            {
                bulls++;
            }
        }

        int cows = 0;
        for(int i = 0; i < 10; i++)
        {
            cows += std::min(guess_digit[i], secret_digit[i]);
        }
        return std::to_string(bulls) + "A" + 
                    std::to_string(cows - bulls) + "B";
    }
};

int main()
{
    Solution sol;
    {
        std::string secret = "1807";
        std::string guess = "7810";
        std::string res = "1A3B";
        assert(sol.getHint(secret, guess) == res);
    }
    {
        std::string secret = "1123";
        std::string guess = "0111";
        std::string res = "1A1B";
        assert(sol.getHint(secret, guess) == res);
    }
    return 0;
}