#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    std::vector<int> points;
    std::vector<std::vector<int>> rects;
    int n;
public:
    Solution(std::vector<std::vector<int>>& rects) 
    {
        n = rects.size();
        points.resize(n);
        
        int i = 0;
        for(std::vector<int> rect: rects)
        {
            int l = std::abs(rect[0] - rect[2]) + 1;
            int w = std::abs(rect[1] - rect[3]) + 1;
            if(i != 0)
            {
                points[i] += points[i - 1];
            }
            points[i] += (l * w);
            i++;
        }
        this->rects = rects;
    }
    
    std::vector<int> pick() 
    {
        int val = rand() % points[n-1];
        int rect = std::upper_bound(points.begin(), 
                        points.end(), val) - points.begin();

        int w = std::abs(rects[rect][0] - rects[rect][2]) + 1;
        if(rect > 0)
        {
            val -= points[rect - 1];
        }
        int x = rects[rect][0] + (val % w);
        int y = rects[rect][1] + (val / w);
        return {x, y};
    }
};

int main()
{
    return 0;
}