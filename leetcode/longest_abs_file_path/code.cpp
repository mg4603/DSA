#include <iostream>
#include <assert.h>

#include <sstream>
#include <unordered_map>

class Solution {
public:
    int lengthLongestPath(std::string input) 
    {
        std::stringstream ss(input);
        std::string temp;

        int res = 0;
        std::unordered_map<int, int> len;

        while(getline(ss, temp, '\n'))
        {
            int level = 0;
            while(temp[level] == '\t')level++;

            if(level == 0)
            {
                len[level] = temp.length();
            }
            else
            {
                len[level] = len[level - 1] + 1 + temp.length() - level;
            }
            if(temp.find('.') != std::string::npos)
            {
                res = std::max(res, len[level]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
        int res = 20;
        assert(sol.lengthLongestPath(input) == res);
    }
    {
        std::string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
        int res = 32;
        assert(sol.lengthLongestPath(input) == res);
    }
    {
        std::string input = "a";
        int res = 0;
        assert(sol.lengthLongestPath(input) == res);
    }
    return 0;
}