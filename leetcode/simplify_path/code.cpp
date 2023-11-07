#include <iostream>
#include <assert.h>

#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        if(path.size() == 1)
        {
            return path;
        }
        
        std::vector<std::string> res;
        std::stringstream ss(path);
        std::string temp;

        while(getline(ss, temp, '/'))
        {
            if(temp == "" || temp == ".")continue;
            if(temp == "..")
            {
                if(res.size() > 0)
                res.pop_back();
                continue;
            }
            res.push_back(temp);
        }
        
        std::string res_path = "/";
        for(int i = 0; i < res.size(); i++)
        {
            if(i != 0)
            {
                res_path += "/";
            }
            res_path += res[i];
        }
        return res_path;
    }
};

int main()
{
    Solution sol;
    {
        std::string path = "/home/";
        std::string res = "/home";
        assert(sol.simplifyPath(path) == res);
    }
    {
        std::string path = "/../";
        std::string res = "/";
        assert(sol.simplifyPath(path) == res);
    }
    {
        std::string path = "/home//foo/";
        std::string res = "/home/foo";
        assert(sol.simplifyPath(path) == res);
    }
    return 0;
}