#include <iostream>
#include <assert.h>

#include <queue>

class Solution {
public:
    int clumsy(int n) {
        std::queue<int> q;
        for(int i = n; i > 0; i -= 4) {
            if(i - 3 > 0) {
                q.push(i * (i - 1) / (i - 2));
                q.push((i - 3));
            }else if(i - 2 > 0) {
                q.push(i * (i - 1) / (i - 2));
            }else if(i - 1 > 0) {
                q.push(i * (i - 1));
            }else {
                q.push(i);
            }
        }
        
        int res = q.front();
        q.pop();
        if(!q.empty()) {
            res += q.front();
            q.pop();
        }
        
        while(!q.empty()) {
            int first = q.front();
            q.pop();
            int second = 0;
            if(!q.empty()) {
                second = q.front();
                q.pop();
            }
            res += second;
            res -= first;            
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 4;
        int res = 7;
        assert(sol.clumsy(n) == res);
    }
    return 0;
}