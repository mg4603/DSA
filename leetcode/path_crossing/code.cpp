#include <iostream>
#include <assert.h>

#include <set>

class Solution {
public:
    bool isPathCrossing(std::string path) {
        std::set<std::pair<int, int>> st;
        std::pair<int, int> current = std::make_pair(0, 0);
        st.insert(current);
        for(int i = 0; i < path.length(); i++)
        {
            switch(path[i])
            {
                case 'N':
                    current.second++;
                    break;
                case 'S':
                    current.second--;
                    break;
                case 'E':
                    current.first++;
                    break;
                case 'W':
                    current.first--;
                    break;
            }

            if(st.find(current) != st.end())
            {
                return true;
            }
            st.insert(current);
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::string path = "NES";
        bool res = false;
        assert(sol.isPathCrossing(path) == res);
    }
    {
        std::string path = "NESWW";
        bool res = true;
        assert(sol.isPathCrossing(path) == res);
    }
    return 0;
}