#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    double calculateTax(std::vector<std::vector<int>>& brackets, int income) 
    {
        double res = 0.0;
        for(int i = 0; i < brackets.size() && income; i ++)    
        {
            int amt = 0;
            if(i > 0)
            {
                amt = std::min(brackets[i][0] - brackets[i - 1][0], income);

            }
            else
            {
                amt = std::min(brackets[i][0], income);
            }
            income -= amt;
            double rate = brackets[i][1] / 100.0;
            res += amt * rate;
        }
        return res;
    }
};

void fuzzy_equal(double a, double b)
{
    assert(std::abs(a - b) <= 10e-5);
}
int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> brackets = {
            {3,50},{7,10},{12,25},};
        int income = 10;
        double res = 2.65000;
        fuzzy_equal(sol.calculateTax(brackets, income), res);
    }
    {
        std::vector<std::vector<int>> brackets = {
            {1,0},{4,25},{5,50},};
        int income = 2;
        double res = 0.25000;
        fuzzy_equal(sol.calculateTax(brackets, income), res);
    }
    {
        std::vector<std::vector<int>> brackets = {
            {2,50},};
        int income = 0;
        double res = 0.00000;
        fuzzy_equal(sol.calculateTax(brackets, income), res);
    }
    return 0;
}