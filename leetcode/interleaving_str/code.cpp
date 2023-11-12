#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool helper(int i, int j, int k, std::string s1, std::string s2, 
                std::string s3, std::vector<std::vector<int>> &table)
    {
        if(k == s3.length())
        {
            return true;
        }

        if(table[i][j] != -1)
        {
            return table[i][j];
        }

        if((i == s1.length() && s2[j] != s3[k]) || 
           (j == s2.length() && s1[i] != s3[k]) || 
           (s1[i] != s3[k] && s2[j] != s3[k]))
        {
            return false;
        }


        if(s2[j] != s3[k] && s1[i] == s3[k])
        {
            return table[i][j] = helper(i + 1, j, k + 1, 
                                        s1, s2, s3, table);
        }
        else if(s1[i] != s3[k] && s2[j] == s3[k])
        {
            return table[i][j] = helper(i, j + 1, k + 1, 
                                        s1, s2, s3, table);
        }        
        else
        {
            return table[i][j] = (helper(i + 1, j, k + 1, 
                                        s1, s2, s3, table) || 
                                  helper(i, j + 1, k + 1, 
                                         s1, s2, s3, table));
        }
    }
public:
    bool isInterleave(std::string s1, 
                      std::string s2, 
                      std::string s3) 
    {
        if(s1.length() + s2.length() != s3.length())
        {
            return false;
        }
        std::vector<std::vector<int>> table(s1.length() + 1, 
                                    std::vector<int>(s2.length() + 1, -1));
        return helper(0, 0, 0, s1, s2, s3, table);
    }
};

int main()
{
    Solution sol;
    {
        std::string s1 = "aabcc";
        std::string s2 = "dbbca";
        std::string s3 = "aadbbcbcac";
        bool res = true;
        assert(sol.isInterleave(s1, s2, s3) == res);
    }
    {
        std::string s1 = "aabcc";
        std::string s2 = "dbbca";
        std::string s3 = "aadbbbaccc";
        bool res = false;
        assert(sol.isInterleave(s1, s2, s3) == res);
    }
    {
        std::string s1 = "";
        std::string s2 = "";
        std::string s3 = "";
        bool res = true;
        assert(sol.isInterleave(s1, s2, s3) == res);
    }
    return 0;
}