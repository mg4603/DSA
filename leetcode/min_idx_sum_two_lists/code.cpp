#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    std::vector<std::string> findRestaurant(std::vector<std::string>& list1, 
                                    std::vector<std::string>& list2) 
    {
        std::vector<std::string> res;
        int index_sum(std::numeric_limits<int>::max());
        for(int i(0); i < list1.size(); i++)
        {
            for(int j(0); j < list2.size(); j++)
            {
                if(list1[i] == list2[j])
                {
                    if(i + j < index_sum)
                    {
                        res.clear();
                        index_sum = i + j;
                        res.push_back(list1[i]);
                    }
                    else if(i + j == index_sum)
                    {
                        res.push_back(list1[i]);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> list1 = {"Shogun","Tapioca Express",
                                            "Burger King","KFC"};
        std::vector<std::string> list2 = {"Piatti","The Grill at Torrey Pines",
                                        "Hungry Hunter Steakhouse","Shogun"};
        std::vector<std::string> res = {"Shogun"};
        
        assert(sol.findRestaurant(list1, list2) == res);
    }
    {
        std::vector<std::string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
        std::vector<std::string> list2 = {"KFC","Shogun","Burger King"};
        std::vector<std::string> res = {"Shogun"};
        
        assert(sol.findRestaurant(list1, list2) == res);
    }
    {
        std::vector<std::string> list1 = {"happy","sad","good"};
        std::vector<std::string> list2 = {"sad","happy","good"};
        std::vector<std::string> res = {"sad","happy"};

        assert(sol.findRestaurant(list2, list1) == res);
    }
    return 0;
}