#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    std::vector<int> table;
    bool dfs(int maxChoosableInteger, 
             int desiredTotal, int state)
    {
        if(table[state] != 0)return table[state] > 0;

        if(desiredTotal <= 0)return false;

        for(int i = 0; i < maxChoosableInteger; i++)
        {
            int temp = 1 << i;
            if(!(state&temp) && 
                !dfs(maxChoosableInteger, 
                    desiredTotal - i - 1, state | temp))
            {
                table[state]=1;
                return true;
            }
        }
        table[state]=-1;
        return false;
    }
public:
    Solution()
    {
        table.resize(1 << 20, 0);
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) 
    {
        if(desiredTotal < maxChoosableInteger)return true;
        
        int total_sum = (maxChoosableInteger * 
                         (maxChoosableInteger + 1) / 2);

        if(desiredTotal > total_sum)return false;

        if(desiredTotal == total_sum)
        {
            return maxChoosableInteger % 2;
        }
        return dfs(maxChoosableInteger, desiredTotal, 0);
    }
};

int main()
{
    Solution sol;
    {
        int maxChoosableInteger = 10;
        int desiredTotal = 11;
        bool res = false;
        assert(sol.canIWin(maxChoosableInteger, desiredTotal) == res);
    }
    {
        int maxChoosableInteger = 10;
        int desiredTotal = 0;
        bool res = true;
        assert(sol.canIWin(maxChoosableInteger, desiredTotal) == res);
    }
    {
        int maxChoosableInteger = 10;
        int desiredTotal = 1;
        bool res = true;
        assert(sol.canIWin(maxChoosableInteger, desiredTotal) == res);
    }
    return 0;
}