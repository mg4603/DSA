#include <iostream>
#include <assert.h>


class NestedInteger {
  public:

    NestedInteger(){
    }

    NestedInteger(int value){
    }

    bool isInteger() const{
    }

    int getInteger() const{
    }

    void setInteger(int value){
    }

    void add(const NestedInteger &ni){
    }

    const vector<NestedInteger> &getList() const
    {
    }
};

class Solution {
    NestedInteger helper(std::stringstream &ss)
    {
        int num;
        if(ss >> num)
        {
            return NestedInteger(num);
        }
        ss.clear();
        ss.get();

        NestedInteger res;
        while(ss.peek() != ']')
        {
            res.add(helper(ss));
            if(ss.peek() == ',')
            {
                ss.get();
            }
        }
        ss.get();
        return res;
    }
public:
    NestedInteger deserialize(std::string s) 
    {
        std::stringstream ss(s);
        return helper(ss);
    }
};

int main()
{
    return 0;
}
