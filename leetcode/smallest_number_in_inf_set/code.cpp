#include <iostream>
#include <assert.h>

#include <queue>
#include <vector>
#include <algorithm>

auto fast = [](){
    std::ios::sync_with_stdio(0);
    return 1;
}();
class SmallestInfiniteSet {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int curr;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(!q.empty()) {
            int smallest = q.top();
            while(!q.empty() && q.top() == smallest)q.pop();
            return smallest;
        }
        return curr++;
    }
    
    void addBack(int num) {
        if(num < curr) {
            q.push(num);
        }
    }
};

int main()
{
    SmallestInfiniteSet smallestInfiniteSet;
    smallestInfiniteSet.addBack(2);
    assert(smallestInfiniteSet.popSmallest() == 1);
    assert(smallestInfiniteSet.popSmallest() == 2);
    assert(smallestInfiniteSet.popSmallest() == 3);
    smallestInfiniteSet.addBack(1);    
    assert(smallestInfiniteSet.popSmallest() == 1);
    assert(smallestInfiniteSet.popSmallest() == 4);
    assert(smallestInfiniteSet.popSmallest() == 5);
    return 0;
}