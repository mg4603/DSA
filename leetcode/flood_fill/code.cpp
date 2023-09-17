#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void dfs(std::vector<std::vector<int>> &image, int row, int col, 
                int original_color, int new_color)
    {
        if(row < 0 || col < 0 || row == image.size() || col == 
            image[0].size() || image[row][col] != original_color)
        {
            return;
        }
        image[row][col] = new_color;
        dfs(image, row - 1, col, original_color, new_color);
        dfs(image, row + 1, col, original_color, new_color);
        dfs(image, row, col - 1, original_color, new_color);
        dfs(image, row, col + 1, original_color, new_color);
    }
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image,
                                         int sr, int sc, int color) {
        if(image[sr][sc] == color)
        {
            return image;
        }
        int original_color = image[sr][sc];
        dfs(image, sr, sc, original_color, color);
        return image;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> image = {
            {1,1,1},
            {1,1,0},
            {1,0,1}
        };
        std::vector<std::vector<int>> res_image = {
            {2,2,2},
            {2,2,0},
            {2,0,1},
        };
        int sr = 1;
        int sc = 1;
        int color = 2;
        assert(sol.floodFill(image, sr, sc, color) == res_image);
    }
    {
        std::vector<std::vector<int>> image = {
            {0,0,0},
            {0,0,0},
        };
        std::vector<std::vector<int>> res_image = {
            {0,0,0},
            {0,0,0},
        };
        int sr = 0;
        int sc = 0;
        int color = 0;
        assert(sol.floodFill(image, sr, sc, color) == res_image);
    }
    return 0;
}