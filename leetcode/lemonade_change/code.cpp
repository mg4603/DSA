#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        int five(0);
        int ten(0);
        for(int bill: bills)
        {
            if(bill == 5)
            {
                five++;
            }
            else if(bill == 10)
            {
                ten++;
                if(five > 0)
                {
                    five--;
                }
                else
                {
                    return false;
                }
            }
            else if(bill == 20)
            {
                if(ten > 0)
                {
                    ten--;
                    if(five > 0)
                    {
                        five--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(five >= 3)
                {
                    five -= 3;
                }
                else
                {
                        return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> bills = {5,5,5,10,20};
        assert(sol.lemonadeChange(bills) == true);
    }
    {
        std::vector<int> bills = {5,5,10,10,20};
        assert(sol.lemonadeChange(bills) == false);
    }
    return 0;
}