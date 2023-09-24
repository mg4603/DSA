#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(
                            std::vector<std::vector<int>>& image) 
    {
        for(int i(0); i < image.size(); i++)
        {
            std::reverse(image[i].begin(), image[i].end());
            std::transform(image[i].begin(), image[i].end(), image[i].begin(), 
                            [](int num){ return !num; });
        }
        return image;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> image = {
            {1,1,0}, 
            {1,0,1}, 
            {0,0,0},
        };
        std::vector<std::vector<int>> res_image = {
            {1,0,0},
            {0,1,0},
            {1,1,1},
        };
        assert(sol.flipAndInvertImage(image) == res_image);
    }
    {
        std::vector<std::vector<int>> image = {
            {1,1,0,0},
            {1,0,0,1},
            {0,1,1,1},
            {1,0,1,0}
        };
        std::vector<std::vector<int>> res_image = {
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,1},
            {1,0,1,0},
        };
        assert(sol.flipAndInvertImage(image) == res_image);
    }
    return 0;
}