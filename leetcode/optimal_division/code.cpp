#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
    struct T
    {
        float max_val, min_val;
        std::string min_str, max_str;
        T()
        {
            min_val = std::numeric_limits<float>::max();
            max_val = std::numeric_limits<float>::min();
            min_str = "";
            max_str = "";
        }
    };
    
    T* helper(std::vector<int> &nums, int start, int end,  
              std::vector<std::vector<T*>> &table)
    {
        if(table[start][end] != nullptr)
        {
            return table[start][end];
        }
        T *t = new T();

        if(start == end)
        {
            t->max_val = nums[start];
            t->min_val = nums[start];
            t->max_str = std::to_string(nums[start]);
            t->min_str = std::to_string(nums[start]);
            table[start][end] = t;
            return t;
        }

        for(int i = start; i < end; i++)
        {
            T *left = helper(nums, start, i, table);
            T *right = helper(nums, i + 1, end, table);
            if(t->min_val > left->min_val / right->max_val)
            {
                t->min_val = left->min_val / right->max_val;
                t->min_str = left->min_str + "/" + 
                                (i + 1 != end ? "(" : "") + 
                                right->max_str + 
                                (i + 1 != end ? ")" : "");
            }

            if(t->max_val < left->max_val / right->min_val)
            {
                t->max_val = left->max_val / right->min_val;
                t->max_str = left->max_str + "/" + 
                                (i + 1 != end ? "(" : "") + 
                                right->min_str + 
                                (i + 1 != end ? ")" : "");
            }
        }
        
        table[start][end] = t;
        return t;
    }

public:
    std::string optimalDivision(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<std::vector<T*>> table(n, 
                                    std::vector<T*>(n));
        T *t = helper(nums, 0, n - 1, table);
        return t->max_str;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int>  nums = {1000,100,10,2};
        std::string res = "1000/(100/10/2)";
        assert(sol.optimalDivision(nums) == res);
    }
    {
        std::vector<int>  nums = {2,3,4};
        std::string res = "2/(3/4)";
        assert(sol.optimalDivision(nums) == res);
    }
    return 0;
}