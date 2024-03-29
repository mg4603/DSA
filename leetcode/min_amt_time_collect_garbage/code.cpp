#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int garbageCollection(std::vector<std::string>& garbage, 
                            std::vector<int>& travel) {

        for(int i = 1; i < travel.size(); i++)
        {
            travel[i] += travel[i - 1];
        }
        travel.insert(travel.begin(), 0);

        std::vector<int> last(3, 0);
        int picks = 0;
        for(int i = 0; i < garbage.size(); i++)
        {
            if(garbage[i].find('G') != std::string::npos)
            {
                last[0] = i;
            }
            if(garbage[i].find('P') != std::string::npos)
            {
                last[1] = i;
            }
            if(garbage[i].find('M') != std::string::npos)
            {
                last[2] = i;
            }
            picks += garbage[i].size();
        }
        
        int res = picks;
        for(int i = 0; i < 3; i++)
        {
            res += travel[last[i]];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> garbage = {"G","P","GP","GG"};
        std::vector<int> travel = {2,4,3};
        int res = 21;
        assert(sol.garbageCollection(garbage, travel) == res);
    }
    return 0;
}