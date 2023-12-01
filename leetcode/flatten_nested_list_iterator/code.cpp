#include <iostream>
#include <assert.h>

#include <vector>

class NestedInteger {
  public:
    bool isInteger() const
    {

    }

    int getInteger() const
    {

    }

    const std::vector<NestedInteger> &getList() const
    {

    }
};


class NestedIterator {
    std::vector<int> list;
    int pos;
    int n;
    std::vector<int> flatten(std::vector<NestedInteger> list)
    {
        std::vector<int> temp;
        for(int i = 0; i < list.size(); i++)
        {
            if(list[i].isInteger())
            {
                temp.push_back(list[i].getInteger());
            }
            else
            {
                std::vector<int> temp2 = flatten(list[i].getList());
                temp.insert(temp.end(), temp2.begin(), temp2.end());
            }
        }
        return temp;
    }   
public:
    NestedIterator(std::vector<NestedInteger> &nestedList) 
    {
        list = flatten(nestedList);
        pos = 0;
        n = list.size();
    }
    
    int next() 
    {
        return list[pos++];
    }
    
    bool hasNext() 
    {
        return pos < n;
    }
};


int main()
{
    return 0;
}