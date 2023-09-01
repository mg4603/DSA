#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class MyHashSet {
    std::vector<int> set;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(std::find(set.begin(), set.end(), key) != set.end())
        {
            return;
        }
        set.push_back(key);
        if(set.size() <= 2)
        {
            std::sort(set.begin(), set.end());
            return;
        }
        int i(set.size() - 2);
        while(i >= 0 && set[i] > key)
        {
            set[i + 1] = set[i];
            i--;
        }
        set[i + 1] = key;
    }
    
    void remove(int key) {
        if(std::find(set.begin(), set.end(), key) == set.end())
        {
            return;
        }
        set.erase(std::remove(set.begin(), set.end(), key));
    }
    
    bool contains(int key) {
        if(std::find(set.begin(), set.end(), key) == set.end())
        {
            return false;
        }
        return true;
    }
};

int main()
{
    MyHashSet myHashSet;
    myHashSet.add(1);      
    myHashSet.add(2);      
    assert(myHashSet.contains(1) == true); 
    assert(myHashSet.contains(3) == false); 
    myHashSet.add(2);      
    assert(myHashSet.contains(2) == true); 
    myHashSet.remove(2);   
    assert(myHashSet.contains(2) == false); 
    return 0;
}