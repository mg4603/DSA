#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
    void dfs(std::string src, std::string dest, std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> &mp, std::unordered_set<std::string> &visited, double temp, double &ans)
    {
        if(visited.find(src) != visited.end())return;

        if(src == dest)
        {
            ans = temp;
        }
        else
        {
            visited.insert(src);
            for(int i = 0; i < mp[src].size(); i++)
            {
                dfs(mp[src][i].first, dest, mp, visited, temp * mp[src][i].second, ans);
            }
        }
    }
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) 
    {
         std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> mp;

         for(int i = 0; i < equations.size(); i++)
         {
             mp[equations[i][0]].push_back(std::make_pair(equations[i][1], values[i]));
             mp[equations[i][1]].push_back(std::make_pair(equations[i][0], 1/values[i]));
         }

         std::vector<double> res;
         std::unordered_set<std::string> visited;

         for(int i = 0; i < queries.size(); i++)
         {
             std::string src = queries[i][0];
             std::string dest = queries[i][1];
             double ans = -1.0;
             visited.clear();
             if(mp.count(src) && mp.count(dest))
             {
                 dfs(src, dest, mp, visited, 1.0, ans);
             }
             res.push_back(ans);
         }   
         return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<std::string>> equations = {{"a","b"},
                                                           {"b","c"}};

        std::vector<std::vector<std::string>> queries = 
                                                {{"a","c"},{"b","a"},
                                                 {"a","e"},{"a","a"},
                                                 {"x","x"}};

        std::vector<double> values = {2.0,3.0};
        std::vector<double> res = {6.00000,0.50000,-1.00000,
                                   1.00000,-1.00000};
        assert(sol.calcEquation(equations, values, queries) == res);
    }
    {
        std::vector<std::vector<std::string>> equations = 
                                            {{"a","b"},
                                             {"b","c"},
                                             {"bc","cd"}};

        std::vector<std::vector<std::string>> queries = 
                                                {{"a","c"},{"c","b"},
                                                {"bc","cd"},{"cd","bc"}};

        std::vector<double> values = {1.5,2.5,5.0};
        std::vector<double> res = {3.75000,0.40000,5.00000,0.20000};

        assert(sol.calcEquation(equations, values, queries) == res);
    }
    {
        std::vector<std::vector<std::string>> equations = {{"a","b"}};
        std::vector<std::vector<std::string>> queries = 
                                                {{"a","b"},{"b","a"},
                                                 {"a","c"},{"x","y"}};
        std::vector<double> values = {0.5};
        std::vector<double> res = {0.50000,2.00000,-1.00000,-1.00000};
        assert(sol.calcEquation(equations, values, queries) == res);
    }
    return 0;
}