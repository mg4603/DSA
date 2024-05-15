#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    std::vector<int> parent;
    int find(int x) {
        if(parent[x] == -1)return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) {
            parent[std::max(x, y)] = std::min(x, y);
        }
    }
public:
    std::string smallestEquivalentString(std::string s1, 
                            std::string s2, 
                            std::string baseStr) {
        parent.clear();
        parent.resize(26, -1);

        for(int i = 0; i < s1.length(); i++) {
            Union(s1[i] - 'a', s2[i] - 'a');
        }
        for(char &c: baseStr) {
            c = find(c - 'a') + 'a';
        }
        return baseStr;
    }
};

int main()
{
    Solution sol;
    {
        std::string s1 = "parker";
        std::string s2 = "morris";
        std::string baseStr = "parser";
        std::string res = "makkek";
        assert(sol.smallestEquivalentString(s1, s2, baseStr) == res);
    }
    return 0;
}