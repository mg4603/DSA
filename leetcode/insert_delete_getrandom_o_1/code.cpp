#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <unordered_map>

class RandomizedSet {
    std::unordered_map<int, int> mp;
    std::vector<int> elems;

public:
    RandomizedSet() 
    {
    }
    
    bool insert(int val) 
    {
        if(mp.find(val) != mp.end())return false;

        elems.push_back(val);
        mp[val] = elems.size() - 1;
        return true;
    }
    
    bool remove(int val) 
    {
        if(mp.find(val) == mp.end())return false;

        int last_elem = elems.back();
        elems.pop_back();
        elems[mp[val]] = last_elem;

        mp[last_elem] = mp[val];
        mp.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        int idx = rand() % elems.size();
        return elems[idx];
    }
};

int main()
{
    RandomizedSet obj;
    assert(obj.insert(1) == true);
    assert(obj.remove(2) == false); 
    assert(obj.insert(2) == true);

    std::vector<int> one_of{1,2};
    assert(std::find(one_of.begin(), one_of.end(), obj.getRandom()) != one_of.end());

    assert(obj.remove(1) == true);
    assert(obj.insert(2) == false);
    assert(obj.getRandom() == 2);
    return 0;
}