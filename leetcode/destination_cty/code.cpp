#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>

class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        std::unordered_set<std::string> origin;
        std::unordered_set<std::string> destination;
        for(int i = 0; i < paths.size(); i++)
        {
            origin.insert(paths[i][0]);
            destination.insert(paths[i][1]);
        }
        for(std::string dst: destination)
        {
            if(origin.find(dst) == origin.end())
            {
                return dst;
            }
        }
        return "";
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<std::string>> paths = {
            {"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
        std::string dest = "Sao Paulo";
        assert(sol.destCity(paths) == dest);
    }
    {
        std::vector<std::vector<std::string>> paths = {
            {"B","C"},{"D","B"},{"C","A"}};
        std::string dest = "A";
        assert(sol.destCity(paths) == dest);
    }
    {
        std::vector<std::vector<std::string>> paths = {
           {"A","Z"}};
        std::string dest = "Z";
        assert(sol.destCity(paths) == dest);
    }
    return 0;
}