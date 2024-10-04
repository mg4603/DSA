#include <iostream>
#include <vector>
#include <climits>

int findMinCost(std::vector<std::vector<int>> &grid, int n, int m) {
    if(n == 0 || m == 0)return INT_MAX;

    if(n == 1 && m == 1)return grid[0][0];
    return std::min(findMinCost(grid, n - 1, m), 
            findMinCost(grid, n, m - 1)) + grid[n - 1][m - 1];
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
    return 0;
}