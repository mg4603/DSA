#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <queue>

auto first = []() {
    std::ios::sync_with_stdio(0);
    return 1;
}();
class SeatManager {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int first;
public:
    SeatManager(int n) {
        first = 1;
    }
    
    int reserve() {
        if(!pq.empty()) {
            int seat = pq.top();
            pq.pop();
            return seat;
        }
        return first++;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};


int main()
{
    SeatManager seatManager(5);
    assert(seatManager.reserve() == 1);
    assert(seatManager.reserve() == 2);
    seatManager.unreserve(2); 
    assert(seatManager.reserve() == 2);    
    assert(seatManager.reserve() == 3);    
    assert(seatManager.reserve() == 4);    
    assert(seatManager.reserve() == 5);    
    seatManager.unreserve(5); 

    return 0;
}