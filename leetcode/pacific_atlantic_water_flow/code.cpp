#include <iostream>
#include <assert.h>

#include <vector>
#include <set>

class Solution {
    int ROWS;
    int COLS;
    
    void dfs(std::vector<std::vector<int>> &heights, 
		    int r, int c, int prevHeight, 
		    std::set<std::pair<int, int>> &visit)
    {
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || 
			heights[r][c] < prevHeight || 
			visit.find(std::make_pair(r, c)) != 
			visit.end())return;

        visit.insert(std::make_pair(r, c));
        dfs(heights, r + 1, c, heights[r][c], visit);
        dfs(heights, r - 1, c, heights[r][c], visit);
        dfs(heights, r, c + 1, heights[r][c], visit);
        dfs(heights, r, c - 1, heights[r][c], visit);
    }

public:
    std::vector<std::vector<int>> pacificAtlantic(
		    std::vector<std::vector<int>>& heights) 
    {
        ROWS = heights.size();
        COLS = heights[0].size();

        std::set<std::pair<int, int>> pacific;
        std::set<std::pair<int, int>> atlantic;

        for(int r = 0; r < ROWS; r++)
        {
            dfs(heights, r, 0, heights[r][0], pacific);
            dfs(heights, r, COLS - 1, 
			    heights[r][COLS - 1], atlantic);
        }

        for(int c = 0; c < COLS; c++)
        {
            dfs(heights, 0, c,
			    heights[0][c], pacific);
            dfs(heights, ROWS - 1, c, 
			    heights[ROWS - 1][c], atlantic);
        }

        std::vector<std::vector<int>> res;
        for(std::pair<int, int> it: pacific)
        {
            if(atlantic.find(it) != atlantic.end())
            {
                res.push_back({it.first, it.second});
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
	std::vector<std::vector<int>> heights = {
		{1,2,2,3,5},
		{3,2,3,4,4},
		{2,4,5,3,1},
		{6,7,1,4,5},
		{5,1,1,2,4}};
	std::vector<std::vector<int>> res = {
		{0,4},{1,3},{1,4},
		{2,2},{3,0},{3,1},
		{4,0}};
        assert(sol.pacificAtlantic(heights) == res);
    }
    {
	std::vector<std::vector<int>> heights = {{1}};
	std::vector<std::vector<int>> res = {{0,0}};
        assert(sol.pacificAtlantic(heights) == res);
    }
    return 0;
}
