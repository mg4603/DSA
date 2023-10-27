#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int minNumberOfHours(int initialEnergy, 
                            int initialExperience, 
                            std::vector<int>& energy, 
                            std::vector<int>& experience) 
    {
        int res = 0;
        int energy_req = std::accumulate(energy.begin(), energy.end(), 0);
        if(energy_req >= initialEnergy)
        {
            res += (energy_req - initialEnergy) + 1;
        }

        for(int i = 0; i < experience.size(); i++)
        {
            if(experience[i] >= initialExperience)
            {
                res += (experience[i] - initialExperience + 1);
                initialExperience += (experience[i] - initialExperience) + 1;
            }
            initialExperience += experience[i];
        }    
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int initialEnergy = 5;
        int initialExperience = 3;
        std::vector<int> energy = {1,4,3,2};
        std::vector<int> experience = {2,6,3,1};
        int res = 8;
        assert(sol.minNumberOfHours(initialEnergy, initialExperience, energy, 
                experience) == res);
    }
    {
        int initialEnergy = 2;
        int initialExperience = 4;
        std::vector<int> energy = {1};
        std::vector<int> experience = {3};
        int res = 0;
        assert(sol.minNumberOfHours(initialEnergy, initialExperience, energy, 
                experience) == res);
    }
    return 0;
}