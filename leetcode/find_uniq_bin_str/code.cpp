#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int toInt(std::string bin) {
        int num = 0;
        for(char &c: bin) {
            num *= 2;
            num += c - '0';
        }
        return num;
    }
    
public:
    std::string findDifferentBinaryString(
                        std::vector<std::string>& nums) {
        int n = nums.size();
        std::vector<int> exists(1 << n, 0);
        for(std::string &num: nums) {
            exists[toInt(num)] = 1;
        }

        for(int i = 0; i < (1 << n); i++) {
            if(!exists[i]) {
                std::string res(n, '0');
                int num = i;
                for(int j = n - 1; j >= 0; num /= 2, j--) {
                    res[j] += (num % 2);
                }
                return res;
            }
        }
        return "";
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> nums = {"01","10"};
        std::string res = "00";
        assert(sol.findDifferentBinaryString(nums) == res);
    }
    return 0;
}