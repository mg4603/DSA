#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    char slowestKey(std::vector<int> &releaseTimes, std::string keysPressed) 
    {
        std::ios_base::sync_with_stdio(0);
        std::pair<int, char> res = std::make_pair(releaseTimes[0], 
                                                  keysPressed[0]);

        for(int i = 1; i < releaseTimes.size(); i++)
        {
            int temp = releaseTimes[i] - releaseTimes[i - 1];
            char temp1 = keysPressed[i];
            if(temp > res.first)
            {
                res.first = temp;
                res.second = temp1;
            }
            else if(temp == res.first && temp1 > res.second)
            {
                res.second = temp1;
            }
        }

        return res.second;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> releaseTimes = {12,23,36,46,62};
        std::string keysPressed = "spuda";
        char res = 'a';
        assert(sol.slowestKey(releaseTimes, keysPressed) == res);
    }
    {
        std::vector<int> releaseTimes = {9,29,49,50};
        std::string keysPressed = "cbcd";
        char res = 'c';
        assert(sol.slowestKey(releaseTimes, keysPressed) == res);
    }
    return 0;
}