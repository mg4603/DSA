#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool dfs(std::vector<std::vector<char>> &board, 
             std::string word, int i, int j, 
             int word_idx)
    {
        if(word_idx == word.length())
        {
            return true;
        }
        if(i < 0 || j < 0 || 
           i > board.size() - 1 || 
           j > board[0].size() - 1 || 
           word_idx > word.length() - 1|| 
           word_idx < 0 || 
           board[i][j] != word[word_idx])
        {
            return false;
        }

        char temp = board[i][j];
        
        board[i][j] = ' ';

        bool found = 
                dfs(board, word, i + 1, j, word_idx + 1) || 
                dfs(board, word, i - 1, j, word_idx + 1) || 
                dfs(board, word, i, j - 1, word_idx + 1) || 
                dfs(board, word, i, j + 1, word_idx + 1);

        board[i][j] = temp;
        return found;
    }
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
        int n = board.size();
        int m = board[0].size();

        if(word == "")return true;
        if(n == 0 || m == 0 )return false;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(word[0] != board[i][j])continue;
                if(dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<char>> board = 
                                        {{'A','B','C','E'},
                                         {'S','F','C','S'},
                                         {'A','D','E','E'}};
        std::string word = "ABCCED";
        bool res = true;
        assert(sol.exist(board, word) == res);
    }
    {
        std::vector<std::vector<char>> board = 
                                        {{'A','B','C','E'},
                                         {'S','F','C','S'},
                                         {'A','D','E','E'}};
        std::string word = "SEE";
        bool res = true;
        assert(sol.exist(board, word) == res);
    }
    {
        std::vector<std::vector<char>> board = 
                                        {{'A','B','C','E'},
                                         {'S','F','C','S'},
                                         {'A','D','E','E'}};
        std::string word = "ABCB";
        bool res = false;
        assert(sol.exist(board, word) == res);
    }
    return 0;
}