#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool haveConflict(std::vector<std::string>& event1, 
                        std::vector<std::string>& event2) 
    {
        std::string latest_start;
        std::string earliest_end;

        if(event1[0] > event2[0])
        {
            latest_start = event1[0];
        }
        else
        {
            latest_start = event2[0];
        }
        if(event1[1] > event2[1])
        {
            earliest_end = event2[1];
        }
        else
        {
            earliest_end = event1[1];
        }
        return latest_start <= earliest_end;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> event1 = {"01:15","02:00"};
        std::vector<std::string> event2 = {"02:00","03:00"};
        bool res = true;
        assert(sol.haveConflict(event1, event2) == res);
    }
    {
        std::vector<std::string> event1 = {"01:00","02:00"};
        std::vector<std::string> event2 = {"01:20","03:00"};
        bool res = true;
        assert(sol.haveConflict(event1, event2) == res);
    }
    {
        std::vector<std::string> event1 = {"10:00","11:00"};
        std::vector<std::string> event2 = {"14:00","15:00"};
        bool res = false;
        assert(sol.haveConflict(event1, event2) == res);
    }
    return 0;
}