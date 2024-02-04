#include <iostream>
#include <assert.h>

#include <map>

class MyCalendarTwo {
    std::map<int , int> cal;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        cal[start]++;
        cal[end]--;
        int booked = 0;
        for(auto it = cal.begin(); it != cal.end(); it++)
        {
            booked += it->second;
            if(booked > 2)
            {
                cal[end]++;
                cal[start]--;
                return false;
            }
        }
        return true;
    }
};

int main()
{
    MyCalendarTwo myCalendarTwo;
    assert(myCalendarTwo.book(10, 20) == true); 
    assert(myCalendarTwo.book(50, 60) == true); 
    assert(myCalendarTwo.book(10, 40) == true); 
    assert(myCalendarTwo.book(5, 15)  == false); 
    assert(myCalendarTwo.book(5, 10)  == true); 
    assert(myCalendarTwo.book(25, 55) == true); 

 


    return 0;
}