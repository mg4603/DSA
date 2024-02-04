#include <iostream>
#include <assert.h>

#include <algorithm>
#include <set>

class MyCalendar {
    std::set<std::pair<int, int>> cal;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = cal.lower_bound({start, end});
        if(next != cal.end() && 
            next->first < end)return false;

        if(next != cal.begin() && 
            (--next)->second > start)return false;

        cal.insert({start, end});
        return true;
    }
};

int main()
{
    MyCalendar myCalendar;
    assert(myCalendar.book(10, 20) == true);
    assert(myCalendar.book(15, 25) == false);
    assert(myCalendar.book(20, 30) == true);
    return 0;
}