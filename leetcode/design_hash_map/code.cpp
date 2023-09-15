#include <iostream>
#include <assert.h>

#include <vector>

class MyHashMap {
    std::vector<int> map;
public:
    MyHashMap() {
        map = std::vector<int>(1000002, -1);
    }
    
    void put(int key, int value) {
        map[key] = value;
    }
    
    int get(int key) {
        return map[key];
    }
    
    void remove(int key) {
        map[key] = -1;
    }
};


int main()
{
    MyHashMap map;
    map.put(1, 1);
    map.put(2, 2);
    assert(map.get(1) == 1);
    assert(map.get(3) == -1);
    map.put(2, 1);
    assert(map.get(2) == 1);
    map.remove(2);
    assert(map.get(2) == -1);
    
    return 0;
}