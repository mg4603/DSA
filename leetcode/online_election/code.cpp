#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <algorithm>

class TopVotedCandidate {
    std::unordered_map<int, int> m;
    std::vector<int> times;
public:
    TopVotedCandidate(std::vector<int>& persons, 
                        std::vector<int>& times) {
        std::unordered_map<int, int> cnt;
        int n = persons.size();
        int lead = -1;
        for(int i = 0; i < n; i++)
        {
            int temp = ++cnt[persons[i]];
            if(cnt[lead] <= temp)
            {
                lead = persons[i];
            }
            m[times[i]] = lead;
        }
        this->times = times;
    }
    
    int q(int t) {
        auto it = --std::upper_bound(times.begin(), 
                                     times.end(), t);
        return m[*it];
    }
};

int main()
{
    std::vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
    std::vector<int> times = {0, 5, 10, 15, 20, 25, 30};
    TopVotedCandidate topVotedCandidate(persons, times);
    assert(topVotedCandidate.q(3) ==  0);
    assert(topVotedCandidate.q(12) == 1);
    assert(topVotedCandidate.q(25) == 1);
    assert(topVotedCandidate.q(15) == 0);
    assert(topVotedCandidate.q(24) == 0);
    assert(topVotedCandidate.q(8) ==  1);
    return 0;
}