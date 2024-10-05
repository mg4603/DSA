#include <iostream>
#include <vector>
#include <climits>

int findMinCost(std::vector<std::vector<int>> &grid, int n, int m) {
    if(n == 0 || m == 0)return INT_MAX;

    if(n == 1 && m == 1)return grid[0][0];
    return std::min(findMinCost(grid, n - 1, m), 
            findMinCost(grid, n, m - 1)) + grid[n - 1][m - 1];
}

int dynamicFindMinCost(std::vector<std::vector<int>> &grid,
                int n, int m, std::vector<std::vector<int>> &memo) {
    
    if(n == 0 || m == 0)return INT_MAX;
    if(n == 1 && m == 1)return grid[0][0];
    if(memo[n][m] != INT_MAX)return memo[n][m];

    memo[n][m] = std::min(dynamicFindMinCost(grid, n - 1, m, memo),
                dynamicFindMinCost(grid, n, m - 1, memo)) + grid[n - 1][m - 1];
    return memo[n][m];
}

int main() {

    std::vector<std::vector<int>> grid = {
        { 4, 7, 8, 6, 4 },
        { 6, 7, 3, 9, 2 },
        { 3, 8, 1, 2, 4 },
        { 7, 1, 7, 3, 7 },
        { 2, 9, 8, 9, 3 }
    };
    int n = grid.size();
    int m = grid[0].size();
    std::cout << "The minimum cost is: " 
        << findMinCost(grid, n, m) 
        << std::endl;;

    std::vector<std::vector<int>> memo(n + 1, 
                std::vector<int>(m + 1, INT_MAX));
    
    std::cout << "The minimum cost(dynamic) is: " 
            << dynamicFindMinCost(grid, n, m, memo) 
            << std::endl;
    return 0;
}