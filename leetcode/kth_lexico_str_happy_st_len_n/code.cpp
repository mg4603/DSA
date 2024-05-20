#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string getHappyString(int n, int &k, 
                    int curr_len = 0, char last_ch = 0) {
        if(curr_len == n)k--;
        else {
            for(char ch = 'a'; ch != 'd'; ch++) {
                if(ch != last_ch)
                {
                    std::string res = getHappyString(n, k, 
                                        curr_len + 1, ch);
                    if(k == 0) {
                        return std::string(1, ch) + res;
                    }
                }
                
                
            }
        }
        return "";
    }
};

int main()
{
    Solution sol;
    {
        int n = 1;
        int k = 3;
        std::string res = "c";
        assert(sol.getHappyString(n, k) == res);
    }
    return 0;
}