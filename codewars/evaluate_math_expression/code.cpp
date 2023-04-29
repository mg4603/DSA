#include <assert.h>
#include <iostream>

#include <stack>
#include <vector>   
#include <string>
#include <algorithm>

int precedence(std::string operator1, std::string operator2){
    if(operator1 == "-ve"){
        return 1;
    }
    else if((operator1 == "*" || operator1 == "/")
        && (operator2 == "+" || operator2 == "-"))
    {
            return 1;
    }
    else if((operator1 == "+" || operator1 == "-")
        && (operator2 == "*" || operator2 == "/"))
    {
        return -1;
    }
    else{
        return 0;
    }
}

double calc(std::string expression){
    std::cout<<"start"<<std::endl;
    std::vector<std::string> postFix;
    size_t idx(0);
    std::string operators("+-/*");
    std::string symbols("+-/*()");
    std::stack<std::string> st;
    expression.erase(std::remove(expression.begin(), expression.end(), ' '), 
                    expression.end());
    while(idx < expression.size()){
        
        if(isdigit(expression.at(idx))){
            std::cout<<"In digit "<<std::stod(expression.substr(idx))<< ' ';
            postFix.push_back(std::to_string(std::stod(expression.substr(idx))));
            idx = expression.find_first_of(symbols, idx);

            std::cout<<(!st.empty()?st.top():"stack empty")<<std::endl;

            
            if(!st.empty() && st.top() == "-ve"){
                std::cout<<"check"<<std::endl;
                postFix.push_back(st.top());
                st.pop();
            }
        }
        else
        {
            if((idx == 0 && expression.at(idx) == '-')||
                (idx > 0 && expression.at(idx) == '-' &&
                symbols.find(expression.at(idx - 1)) != std::string::npos &&
                expression.at(idx - 1) != ')'))
            {
                st.push("-ve");
                idx ++;
                std::cout<<"after -ve "<<expression.at(idx)<<std::endl;
            }
            else if(st.empty() ||
                precedence(expression.substr(idx, 1), st.top()) == 1 ||
                expression.at(idx) == '(')
            {
                st.push(expression.substr(idx, 1));
                idx++;
            }
            else if(expression.at(idx) == ')')
            {
                while(st.top().at(0) != '('){
                    postFix.push_back(st.top());
                    std::cout<<"In ( "<<st.top()<<std::endl;
                    st.pop();
                }
                st.pop();
                idx++;
            }
            else
            {
                while((!st.empty() && st.top() != "(")
                    && precedence(st.top(), expression.substr(idx, 1)) >= 0)
                {
                    postFix.push_back(st.top());
                    st.pop();
                }
                st.push(expression.substr(idx, 1));
                std::cout<<"operators cond: "<<expression.substr(idx, 1)<<' '<<st.top()<<std::endl;
                idx++;
            }
        }
    }
    while(!st.empty()){
        postFix.push_back(st.top());
        st.pop();
    }
    
    for(std::string ele: postFix){
        std::cout<<ele<<std::endl;
        if(operators.find(ele) != std::string::npos){
            double a = std::stod(st.top());
            st.pop();
            double b = std::stod(st.top());
            st.pop();
            if(ele == "+"){
                st.push(std::to_string(a + b));
            }else if(ele == "-"){
                st.push(std::to_string(b - a));
            }else if(ele == "*"){
                st.push(std::to_string(a * b));
            }else if(ele == "/"){
                st.push(std::to_string(b / a));
            }

        }else if (ele == "-ve"){
            double a = std::stod(st.top());
            st.pop();
            st.push(std::to_string(-a));
        }else{
            st.push(ele);
        }
    }

    std::cout<<std::stod(st.top())<<std::endl<<std::endl;
    return std::stod(st.top());
}

int main(){
    assert(calc("1 + 1") == 2);
    assert(calc("8/16") == 0.5);
    assert(calc("3 -(-1)") == 4);
    assert(calc("2 + -2") == 0);
    assert(calc("10- 2- -5") == 13);
    assert(calc("(((10)))") == 10);
    assert(calc("3 * 5") == 15);
    assert(calc("-7 * -(6 / 3)") == 14);
    return 0;
}