#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void helper(int n, int pos, std::vector<bool> &visited, int &count)
    {
        if(pos > n)
        {
            count++;
            return;
        }

        for(int i = 1; i <= n; i++)
        {
            if(!visited[i] && (pos % i == 0|| i % pos == 0))
            {
                visited[i] = 1;
                helper(n, pos + 1, visited, count);
                visited[i] = 0;
            }
        }
    }
public:
    int countArrangement(int n) 
    {
        std::vector<bool> visited(n + 1, 0);
        int count = 0;
        helper(n, 1, visited, count);
        return count;    
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        int res = 2;
        assert(sol.countArrangement(n) == res);
    }
    {
        int n = 1;
        int res = 1;
        assert(sol.countArrangement(n) == res);
    }
    return 0;
}