#include <assert.h>
#include <vector>
#include <algorithm>

long queueTime(std::vector<int> customers, int n){
    std::vector<int> queue(n, 0);
    for(auto customer: customers){
        *std::min_element(queue.begin(), queue.end()) += customer;
    }
    return *std::max_element(queue.begin(), queue.end());
}

int main(){
    assert(queueTime(std::vector<int>{}, 1) == 0);
    assert(queueTime(std::vector<int>{1,2,3,4}, 1) == 10);
    assert(queueTime(std::vector<int>{2,2,3,3,4,4}, 2) == 9);
    assert(queueTime(std::vector<int>{1,2,3,4,5}, 100) == 5);
    return 0;
}