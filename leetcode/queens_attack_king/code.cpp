#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    
public:
    std::vector<std::vector<int>> queensAttacktheKing(
                            std::vector<std::vector<int>>& queens, 
                            std::vector<int>& king) {

        std::vector<std::vector<int>> board(8, 
                                std::vector<int>(8, 0));
        for(std::vector<int> &queen: queens) {
            board[queen[0]][queen[1]] = 1;
        }
        std::vector<std::vector<int>> res;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i == 0 && j == 0)continue;
                int x = king[0];
                int y = king[1];
                while(x >= 0 && y >= 0 && x < 8 && y < 8) {
                    if(board[x][y]) {
                        res.push_back({x, y});
                        break;
                    }
                    x += i;
                    y += j;
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
        std::vector<std::vector<int>> queens = {{0,1},{1,0},{4,0},
                                                {0,4},{3,3},{2,4}};
        std::vector<int> king = {0,0};
        std::vector<std::vector<int>> res = {{0, 1}, {1, 0}, {3, 3}};
        assert(sol.queensAttacktheKing(queens, king) == res);
    }
    return 0;
}