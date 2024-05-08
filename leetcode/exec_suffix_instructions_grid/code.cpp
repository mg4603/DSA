#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> executeInstructions(int n, 
                        std::vector<int>& startPos, 
                        std::string s) {
        std::ios::sync_with_stdio(0);
        int s_len = s.length();
        std::vector<int> res(s_len);
        for(int i = 0; i < s_len; i++) {
            int cnt = 0;
            int x = startPos[0];
            int y = startPos[1];
            for(int j = i; j < s_len; j++) {
                if(s[j] == 'L') {
                    y -= 1;
                }
                else if(s[j] == 'R') {
                    y += 1;
                }
                else if(s[j] == 'U') {
                    x -= 1;
                }
                else if(s[j] == 'D') {
                    x += 1;
                }

                if(x < 0 || x >= n)break;
                if(y < 0 || y >= n)break;
                cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        std::vector<int> startPos = {0,1};
        std::string s = "RRDDLU";
        std::vector<int> res = {1,5,4,3,1,0};
        assert(sol.executeInstructions(n, startPos, s) == res);
    }
    return 0;
}