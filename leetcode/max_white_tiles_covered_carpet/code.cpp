#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    int maximumWhiteTiles(std::vector<std::vector<int>>& tiles, 
                            int carpetLen) {
        std::ios::sync_with_stdio(0);
        std::sort(tiles.begin(), tiles.end());
        int res = 0;
        int i = 0;
        int j = 0; 
        int cover = 0;
        int partial = 0;

        while(i < tiles.size() && res < carpetLen)
        {
            if(tiles[j][0] + carpetLen > tiles[i][1])
            {
                cover += (tiles[i][1] - tiles[i][0] + 1);
                res = std::max(res, cover);
                i++;
            }
            else
            {
                int partial = tiles[j][0] + carpetLen - tiles[i][0];
                res = std::max(res, cover + partial);
                cover -= (tiles[j][1] - tiles[j][0] + 1);
                j++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> tiles = {{1,5},{10,11},
                                            {12,18},{20,25},{30,32}};
        int carpetLen = 10;
        int res = 9;
        assert(sol.maximumWhiteTiles(tiles, carpetLen) == res);
    }
    return 0;
}