#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        std::queue<std::vector<int>> q;
        std::vector<std::vector<int>> visited(n, 
                                        std::vector<int>(m, 0));
        std::vector<int> d_row = {0,0,-1,1};
        std::vector<int> d_col = {-1,1,0,0}; 
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == 0)
                {

                    res++;
                    q.push({i, j});

                    while(!q.empty())
                    {
                        int row = q.front()[0];
                        int col = q.front()[1];
                        q.pop();
                        visited[row][col] = 1;
                        for(int k = 0; k < 4; k++)
                        {
                            int r1 = row + d_row[k];
                            int c1 = col + d_col[k];
                            if(r1 >= 0 && r1 < n && 
                               c1 >= 0 && c1 < m && 
                               visited[r1][c1] == 0 && 
                               grid[r1][c1] == '1')
                            {
                                visited[r1][c1] = 1;
                                q.push({r1, c1});
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<char>> grid = 
                {{'1','1','1','1','0'},
                 {'1','1','0','1','0'},
                 {'1','1','0','0','0'},
                 {'0','0','0','0','0'}};
        int res = 1;
        assert(sol.numIslands(grid) == res);
    }
    {
        std::vector<std::vector<char>> grid = 
                {{'1','1','0','0','0'},
                 {'1','1','0','0','0'},
                 {'0','0','1','0','0'},
                 {'0','0','0','1','1'}};
        int res = 3;
        assert(sol.numIslands(grid) == res);
    }
    return 0;
}