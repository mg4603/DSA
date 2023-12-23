#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <sstream>

class Solution {
    std::pair<std::string, std::vector<std::string>> parsePath(
                                                    std::string s)
    {
        std::stringstream ss(s);
        
        std::string path;
        ss >> path;

        std::vector<std::string> files;
        std::string temp;
        while(ss >> temp)
        {
            files.push_back(temp);
        }
        return std::make_pair(path, files);
    }
public:
    std::vector<std::vector<std::string>> findDuplicate(
                                std::vector<std::string>& paths) 
    {
        std::unordered_map<std::string,
                        std::vector<std::string>> mp;

        for(int i = 0; i < paths.size(); i++)
        {
            std::pair<std::string, 
                std::vector<std::string>> path = parsePath(paths[i]);

            for(auto it: path.second)
            {
                int pos = it.find('(');
                std::string file = it.substr(0, pos);
                std::string content = it.substr(pos);
                mp[content].push_back(path.first + "/" + file);
            }
        }

        std::vector<std::vector<std::string>> res;
        for(auto it: mp)
        {
            if(it.second.size() > 1)
            {
                res.push_back(it.second);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)",
                                          "root/c 3.txt(abcd)",
                                          "root/c/d 4.txt(efgh)",
                                          "root 4.txt(efgh)"};
        std::vector<std::vector<std::string>> res = {
                    {"root/a/2.txt","root/c/d/4.txt","root/4.txt"},
                    {"root/a/1.txt","root/c/3.txt"}};

        assert(sol.findDuplicate(paths) == res);
    }
    {
        std::vector<std::string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)",
                                          "root/c 3.txt(abcd)",
                                          "root/c/d 4.txt(efgh)"};

        std::vector<std::vector<std::string>> res = {
                    {"root/a/2.txt","root/c/d/4.txt"},
                    {"root/a/1.txt","root/c/3.txt"}};
                    
        assert(sol.findDuplicate(paths) == res);
    }
    return 0;
}