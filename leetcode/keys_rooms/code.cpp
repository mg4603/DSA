#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>
#include <queue>

class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        int n = rooms.size();
        std::vector<int> visited(n, 0);

        std::queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int room = q.front();
            q.pop();
            if(visited[room])continue;
            visited[room] = 1;
            for(auto key: rooms[room]) {
                q.push(key);
            }

        }
        return std::accumulate(visited.begin(), 
                            visited.end(), 0) == n;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> rooms = {{1},{2},{3},{}};
        bool res = true;
        assert(sol.canVisitAllRooms(rooms) == res);
    }
    return 0;
}