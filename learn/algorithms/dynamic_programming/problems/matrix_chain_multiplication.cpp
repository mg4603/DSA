#include <vector>
#include <iostream>
#include <climits>

int matrixChainMultiplication(std::vector<int> &dims, int i, int j) {
    if(j <= i + 1)return 0;

    int min_cost = INT_MAX;
    for(int k = i + 1; k < j; k++) {
        int cost = matrixChainMultiplication(dims, i, k);
        cost += matrixChainMultiplication(dims, k, j);
        cost += dims[i] * dims[k] * dims[j];
        min_cost = std::min(min_cost, cost);
    }
    return min_cost;
}

int main() {
    std::vector<int> dims = {10, 30, 5, 60};
    int n = dims.size();

    std::cout << "The minimum cost is: " 
            << matrixChainMultiplication(dims, 0, n - 1)
            << std::endl;;
    return 0;
}