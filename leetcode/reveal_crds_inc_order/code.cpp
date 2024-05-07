#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
        std::ios::sync_with_stdio(0);
        int n = deck.size();
        std::sort(deck.begin(), deck.end());
        std::vector<int> res(n);
        std::queue<int> q;
        for(int i = 0; i < n; i++)q.push(i);

        for(int i = 0; i < n; i++)
        {
            res[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> deck = {17,13,11,2,3,5,7};
        std::vector<int> res = {2,13,3,11,5,17,7};
        assert(sol.deckRevealedIncreasing(deck) == res);
    }
    return 0;
}