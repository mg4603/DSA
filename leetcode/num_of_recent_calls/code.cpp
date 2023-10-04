#include <iostream>
#include <assert.h>

#include <queue>

class RecentCounter {
    std::queue<int> calls;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        
        while(this->calls.size() && std::abs(this->calls.front() - t) > 3000)
        {
            this->calls.pop();
        }
        this->calls.push(t);
        return this->calls.size();
    }
};


int main()
{
    RecentCounter counter;
    assert(counter.ping(1) == 1);
    assert(counter.ping(100) == 2);
    assert(counter.ping(3001) == 3);
    assert(counter.ping(3003) == 3);
    return 0;
}