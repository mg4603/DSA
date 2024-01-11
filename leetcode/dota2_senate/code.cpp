#include <iostream>
#include <assert.h>

#include <queue>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) 
    {
        std::queue<int> d;
        std::queue<int> r;

        int i;
        for(i = 0; i < senate.size(); i++)
        {
            if(senate[i] == 'D')
            {
                d.push(i);
            }
            else
            {
                r.push(i);
            }
        }

        while(!d.empty() && !r.empty())
        {
            int temp1 = d.front();
            int temp2 = r.front();
            d.pop();
            r.pop();
            if(temp1 < temp2)
            {
                d.push(i);
            }
            else
            {
                r.push(i);
            }
            i++;
        }
        return d.empty() ? "Radiant" : "Dire";
    }
};

int main()
{
    Solution sol;
    {
        std::string senate = "RD";
        std::string res = "Radiant";
        assert(sol.predictPartyVictory(senate) == res);
    }
    {
        std::string senate = "RDD";
        std::string res = "Dire";
        assert(sol.predictPartyVictory(senate) == res);
    }
    return 0;
}