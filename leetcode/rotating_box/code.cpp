#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(
                        std::vector<std::vector<char>>& box) {
        std::ios::sync_with_stdio(0);
        int n = box.size();
        int m = box[0].size();

        for(int i = 0; i < n; i++) {
            int pos = m - 1;
            for(int j = m - 1; j >= 0; j--) {
                if(box[i][j] == '#') {
                    std::swap(box[i][j], box[i][pos]);
                    pos--;
                }else if(box[i][j] == '*'){
                    pos = j - 1;
                }
            }
        }

        std::vector<std::vector<char>> res(m, std::vector<char>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i][j] = box[n - 1 - j][i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<char>> box = {{'#','.','#'}};
        std::vector<std::vector<char>> res = {{'.'},{'#'},
                                              {'#'}};
        assert(sol.rotateTheBox(box) == res);
    }
    return 0;
}