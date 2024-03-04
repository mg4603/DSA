#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int window = n - k;

        long long res = 0;
        long long runningSum = std::accumulate(cardPoints.begin(), 
                                        cardPoints.end(), 0);
        if(window == 0)return runningSum;
        
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            runningSum -= cardPoints[i];
            if(i - j + 1 == window)    
            {
                res = std::max(res, runningSum);
                runningSum += cardPoints[j++];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> cardPoints = {1,2,3,4,5,6,1};
        int k = 3;
        int res = 12;
        assert(sol.maxScore(cardPoints, k) == res);
    }
    return 0;
}