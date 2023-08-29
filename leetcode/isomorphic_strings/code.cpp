#include <iostream>
#include <assert.h>

#include <map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if(s.length() != t.length())
        {
          return false;
        }
        std::map<char, char> replacements;
        std::map<char, bool> used;
        for(int i(0); i < s.length(); i++)
        {
          if(replacements.count(s[i]))
          {
            if(t[i] != replacements[s[i]])
            {
              return false;
            }
          }
          else
          {
            if(used.count(t[i]))
            {
              return false;
            }
            
            replacements[s[i]] = t[i];
            used[t[i]] = true;
          }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.isIsomorphic("egg", "add") == true);
        assert(sol.isIsomorphic("foo", "bar") == false);
        assert(sol.isIsomorphic("paper", "title") == true);
    }
    return 0;
}