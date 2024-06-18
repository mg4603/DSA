#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::ios::sync_with_stdio(0);
        std::vector<int> res;
        
        std::string digits = "123456789";
        int size = log10(low) + 1;
        int left = 0;

        while(left + size <= 9 && 
            std::stoi(digits.substr(left, size)) < low) {
            left++;
            if(left + size > 9) {
                left = 0;
                size++;
            }
        }

        while(left + size <= 9 && 
            std::stoi(digits.substr(left, size)) <= high) {
            res.push_back(std::stoi(digits.substr(left, size)));
            left++;
            if(left + size > 9) {
                left = 0;
                size++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int low = 100, high = 300;
        std::vector<int> res = {123,234};
        assert(sol.sequentialDigits(low, high) == res);
    }
    return 0;
}