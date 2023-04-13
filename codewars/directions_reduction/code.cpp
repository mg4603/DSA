#include<stack>
#include <string>
#include <vector>
#include<map>
#include<assert.h>
#include<bits/stdc++.h>
class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr);
};


void testequal(std::vector<std::string> ans, std::vector<std::string> sol)
{
    assert(ans == (sol));
}
int main(){
        std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
        std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
        std::vector<std::string> sol1 = {"WEST"};
        testequal(ans1, sol1);

        std::vector<std::string> d2 = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH"};
        std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
        std::vector<std::string> sol2 = {"NORTH"};
        testequal(ans2, sol2);

};

std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr){
    std::map<std::string, std::string> table;
    table["NORTH"] = "SOUTH";
    table["SOUTH"] = "NORTH";
    table["EAST"] = "WEST";
    table["WEST"] = "EAST";

    std::vector<std::string> res = std::vector<std::string>();
    std::stack<std::string> st;
    for(std::string direction: arr){
        if(st.empty()){
            st.push(direction);
        }else{
            if(st.top() == table.at(direction)){
                st.pop();
            }else{
                st.push(direction);
            }
        }
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    std::reverse(res.begin(), res.end());
    return res;
}