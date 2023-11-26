#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    std::vector<int> helper(std::string &s, 
                        std::vector<std::vector<std::vector<int>>> &table, 
                        int l, int r)
    {
        if(table[l][r].size() != 0)
        {
            return table[l][r];
        }
        int len = r - l + 1;
        if(len <= 2)
        {
            return {std::stoi(s.substr(l, len))};
        }
        
        std::vector<int> res;
        std::string symbols = "+-*";
        
        for(int i = l; i <= r; i++)
        {
            if(symbols.find(s[i]) != std::string::npos)
            {
                std::vector<int> left = helper(s, table, l, i - 1);
                std::vector<int> right = helper(s, table, i + 1, r);


                for(int j = 0; j < left.size(); j++)
                {
                    for(int k = 0; k < right.size(); k++)
                    {
                        int temp = 0;

                        switch(s[i])
                        {
                            case '+':
                                temp = left[j] + right[k];
                                break;
                            case '*':
                                temp = left[j] * right[k];
                                break;
                            case '-':
                                temp = left[j] - right[k];
                                break;
                        }
                        res.push_back(temp);
                    }
                }
            }
        }
        table[l][r] = res;
        return res;
    }
public:
    std::vector<int> diffWaysToCompute(std::string expression) 
    {
        int n = expression.length();
        std::vector<std::vector<std::vector<int>>> table(n, 
                                        std::vector<std::vector<int>>(n));
        return helper(expression, table, 0, expression.length() - 1);
    }
};

int main()
{
    Solution sol;
    {
        std::string expression = "2-1-1";
        std::vector<int> res = {2,0};
        assert(sol.diffWaysToCompute(expression) == res);
    }
    {
        std::string expression = "2*3-4*5";
        std::vector<int> res = {-34,-10,-14,-10,10};
        assert(sol.diffWaysToCompute(expression) == res);
    }
    return 0;
}