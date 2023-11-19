#include <iostream>
#include <assert.h>

#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    int evalRPN(std::vector<std::string> &tokens) 
    {
        std::stack<std::string> st;
        std::unordered_map<std::string, char> operators{
            {"+", '+'},{"-", '-'},
            {"*", '*'},{"/", '/'}
        };
        for(int i = 0; i < tokens.size(); i++)
        {
            if(operators.find(tokens[i]) != operators.end())
            {
                int b = std::stoi(st.top());
                st.pop();
                int a = std::stoi(st.top());
                st.pop();
                
                switch(operators[tokens[i]])
                {
                    case '+':
                        a += b;
                        break;
                    case '-':
                        a -= b;
                        break;
                    case '*':
                        a *= b;
                        break;
                    case '/':
                        a /= b;
                        break;
                }
                st.push(std::to_string(a));
            }
            else
            {
                st.push(tokens[i]);
            }
        }
        return std::stoi(st.top());
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> tokens = {"2","1","+","3","*"};
        int res = 9;
        assert(sol.evalRPN(tokens) == res);
    }
    {
        std::vector<std::string> tokens = {"4","13","5","/","+"};
        int res = 6;
        assert(sol.evalRPN(tokens) == res);
    }
    {
        std::vector<std::string> tokens = {"10","6","9","3","+","-11",
                                            "*","/","*","17","+","5","+"};
        int res = 22;
        assert(sol.evalRPN(tokens) == res);
    }
    return 0;
}