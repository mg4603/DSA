#include <assert.h>
#include <iostream>

#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using msv = std::map<std::string, std::vector<char>>;

msv remove_duplicate_ids(const msv &obj) {
    std::set<char> allChs;
    std::map<std::string, std::vector<char>> res;
    std::map<int, std::vector<char>, std::greater<int>> newObj;
    for(auto ele: obj)
    {
        newObj[stoi(ele.first)] = std::vector<char>();
        for(char c: ele.second)
        {
            newObj[stoi(ele.first)].push_back(c);
        }
    }

    for(auto ele: newObj)
    {
        std::set<char> inObjChs;
        res[std::to_string(ele.first)] = std::vector<char>();
        for(char c: ele.second)
        {
            if(allChs.find(c) == allChs.end() && inObjChs.find(c) == inObjChs.end())
            {
                inObjChs.insert(c);
                allChs.insert(c);
                res[std::to_string(ele.first)].push_back(c);
            }
        }
    }
    return res;
}

int main()
{
    msv a = {
        {"1", {'A', 'B', 'C'}},
        {"2", {'A', 'B', 'D', 'A'}},
    };
    msv res_a = {
        {"1", {'C'}},
        {"2", {'A', 'B', 'D'}}
    };
    assert(remove_duplicate_ids(a) == res_a);
    
    msv b = {
        {"1", {'C', 'F', 'G'}},
        {"2", {'A', 'B', 'C'}},
        {"3", {'A', 'B', 'D'}},
    };
    msv res_b = {
        {"1", {'F', 'G'}},
        {"2", {'C'}},
        {"3", {'A', 'B', 'D'}}
    };
    assert(remove_duplicate_ids(b) == res_b);
    
    msv c = {
        {"1", {'A'}},
        {"2", {'A'}},
        {"3", {'A'}},
    };
    msv res_c = {
        {"1", {}},
        {"2", {}},
        {"3", {'A'}}
    };
    assert(remove_duplicate_ids(c) == res_c);
    
    msv d = {
        {"432", {'A', 'A', 'B', 'D'}},
        {"53", {'L', 'G', 'B', 'C'}},
        {"236", {'L', 'A', 'X', 'G', 'H', 'X'}},
        {"11", {'P', 'R', 'S', 'D'}},
    };
    msv res_d = {
        {"11", {'P', 'R', 'S'}},
        {"53", {'C'}},
        {"236", {'L', 'X', 'G', 'H'}},
        {"432", {'A', 'B', 'D'}},
    };
    assert(remove_duplicate_ids(d) == res_d);
    return 0;
}