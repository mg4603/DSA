#include <iostream>
#include <assert.h>

#include <vector>

class StockSpanner {
    std::vector<std::pair<int, int>> st;
    int day;
public:
    StockSpanner() {
        std::ios::sync_with_stdio(0);
        day = 0;
    }
    
    int next(int price) {
        day++;
        while(!st.empty() &&  
              st.back().first <= price)st.pop_back();
        int res = 0;
        if(st.empty()) {
            res = day;
        } else {
            res = day - st.back().second;
        }
        st.push_back({price, day});
        return res;
    }
};

int main()
{
    StockSpanner stockSpanner;
    assert(stockSpanner.next(100) == 1);
    assert(stockSpanner.next(80) == 1);
    assert(stockSpanner.next(60) == 1);
    assert(stockSpanner.next(70) == 2);
    assert(stockSpanner.next(60) == 1);
    assert(stockSpanner.next(75) == 4);
    assert(stockSpanner.next(85) == 6);
    return 0;
}