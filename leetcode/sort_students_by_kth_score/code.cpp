#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> sortTheStudents(
                std::vector<std::vector<int>>& score, int k) {
        std::ios::sync_with_stdio(0);
        std::sort(score.begin(), score.end(), 
                    [&](const std::vector<int> &a, 
                    const std::vector<int> &b) {
            return a[k] > b[k];
        });
        return score;
    }
};

int main()
{
    return 0;
}