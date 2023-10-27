#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
    std::vector<int> getTimeVec(std::string time)
    {
        std::vector<int> vec(2, 0);
        vec[0] = std::stoi(time);
        vec[1] = std::stoi(time.substr(3));
        return vec;
    }
public:
    int countDaysTogether(std::string arriveAlice, 
                          std::string leaveAlice, 
                          std::string arriveBob, 
                          std::string leaveBob) 
    {
        std::vector<int> days = {31, 28, 31, 30, 31, 30, 
                                 31, 31, 30, 31, 30, 31};

        std::vector<int> arrive_alice_vec = getTimeVec(arriveAlice);
        std::vector<int> leave_alice_vec = getTimeVec(leaveAlice);

        std::vector<int> arrive_bob_vec = getTimeVec(arriveBob);
        std::vector<int> leave_bob_vec = getTimeVec(leaveBob);


        int arrive_alice_days = std::accumulate(days.begin(), 
                                    days.begin() + arrive_alice_vec[0] - 1, 
                                    0) + arrive_alice_vec[1];

        int leave_alice_days = std::accumulate(days.begin(), 
                                    days.begin() + leave_alice_vec[0] - 1, 
                                    0) + leave_alice_vec[1];


        int arrive_bob_days = std::accumulate(days.begin(), 
                                    days.begin() + arrive_bob_vec[0] - 1, 
                                    0) + arrive_bob_vec[1];

        int leave_bob_days = std::accumulate(days.begin(), 
                                    days.begin() + leave_bob_vec[0] - 1, 
                                    0) + leave_bob_vec[1];

        int latest_arrival = std::max(arrive_alice_days, arrive_bob_days);
        int earliest_departure = std::min(leave_alice_days, leave_bob_days);


        return earliest_departure >= latest_arrival ? 
                        earliest_departure - latest_arrival + 1: 0;
    }
};

int main()
{
    Solution sol;
    {
        std::string arriveAlice = "08-15";
        std::string leaveAlice = "08-18";
        std::string arriveBob = "08-16";
        std::string leaveBob = "08-19";
        int res = 3;
        assert(sol.countDaysTogether(arriveAlice, leaveAlice, 
                arriveBob, leaveBob) == res);
    }
    {
        std::string arriveAlice = "10-01";
        std::string leaveAlice = "10-31";
        std::string arriveBob = "11-01";
        std::string leaveBob = "12-31";
        int res = 0;
        assert(sol.countDaysTogether(arriveAlice, leaveAlice, 
                arriveBob, leaveBob) == res);
    }
    return 0;
}