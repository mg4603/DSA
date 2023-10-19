#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minOperations(std::vector<std::string>& logs) {
        int res = 0;
        std::ios_base::sync_with_stdio(0);
        for(int i = 0; i < logs.size(); i++)
        {
            if(logs[i] != "./" && logs[i] != "../")
            {
                res++;
            }else if(logs[i] == "../" && res > 0)
            {
                res--;
            }

        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> logs = {"d1/","d2/","../","d21/","./"};
        int res = 2;
        assert(sol.minOperations(logs) == res);
    }
    {
        std::vector<std::string> logs = {"d1/","d2/","./","d3/","../","d31/"};
        int res = 3;
        assert(sol.minOperations(logs) == res);
    }
    {
        std::vector<std::string> logs = {"d1/","../","../","../"};
        int res = 0;
        assert(sol.minOperations(logs) == res);
    }
    return 0;
}