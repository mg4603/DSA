#include <iostream>
#include <assert.h>

#include <limits>
#include <vector>
#include <map>

class Solution {
    int gcd(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
public:
    bool hasGroupsSizeX(std::vector<int>& deck) {
        std::map<int, int> freq;

        for(int card: deck)
        {
            freq[card]++;
        }
        int x(freq.begin()->second);
        for(auto pair: freq)
        {
            x = gcd(x, pair.second);
            if(x == 1)
            {
                return false;
            }
        }
        
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> deck = {1,2,3,4,4,3,2,1};
        bool output = true;
        assert(sol.hasGroupsSizeX(deck) == output);
    }
    {
        std::vector<int> deck = {1,1,1,2,2,2,3,3};
        bool output = false;
        assert(sol.hasGroupsSizeX(deck) == output);
    }
    return 0;
}