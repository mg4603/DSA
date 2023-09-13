#include <iostream>
#include <assert.h>

#include <stack>
#include <vector>

class Solution {
public:
    int calPoints(std::vector<std::string>& ops) {
        std::stack<int> rec;
        for(std::string op: ops)
        {
            if(op == "+")
            {
                int temp = rec.top();
                rec.pop();
                int sum = rec.top() + temp;
                rec.push(temp);
                rec.push(sum);
            }
            else if(op == "D")
            {
                rec.push(rec.top() * 2);
            }
            else if(op == "C")
            {
                rec.pop();
            }
            else
            {
                rec.push(std::stoi(op));
            }
        }
        int res(0);
        while(!rec.empty())
        {
            res += rec.top();
            rec.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> ops = {"5","2","C","D","+"};
        assert(sol.calPoints(ops) == 30);
    }
    {
        std::vector<std::string> ops = {"5","-2","4","C","D","9","+","+"};
        assert(sol.calPoints(ops) == 27);
    }
    {
        std::vector<std::string> ops = {"1","C"};
        assert(sol.calPoints(ops) == 0);
    }

    return 0;
}