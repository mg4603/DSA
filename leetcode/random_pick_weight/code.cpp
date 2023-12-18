#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    std::vector<int> w;
    int n;
public:
    Solution(std::vector<int>& w) 
    {
        this->n = w.size();
        for(int i = 1; i < n; i++)
        {
            w[i] += w[i - 1];
        }
        this->w = w;
    }
    
    int pickIndex() 
    {
        int val = rand() % w[n-1];
        auto it = std::upper_bound(w.begin(), w.end(), val);
        return it - w.begin();
    }
};

int main()
{
    return 0;
}