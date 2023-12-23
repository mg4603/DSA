#include <iostream>
#include <assert.h>

#include <queue>
#include <vector>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) 
    {
        std::vector<int> freq(26, 0);
        for(int i = 0; i < tasks.size(); i++)
        {
            freq[tasks[i] - 'A']++;
        }

        std::priority_queue<int> q;
        for(int i = 0; i < 26; i++)
        {
            if(freq[i])
            {
                q.push(freq[i]);
            }
        }

        int res = 0;
        while(!q.empty())
        {
            int cycle = n + 1;
            std::vector<int> remain;
            while(cycle && !q.empty())
            {
                int temp = q.top();
                q.pop();
                if(temp > 1)
                {
                    remain.push_back(temp-1);    
                }
                cycle--;
                res++;
            }

            for(int num: remain)
            {
                q.push(num);
            }
            if(q.empty())break;
            res += cycle;
        }
        return res;        
    }
};

int main()
{
    Solution sol;
    {
        std::vector<char> tasks = {'A','A','A','B','B','B'};
        int n = 2;
        int res = 8;
        assert(sol.leastInterval(tasks, n) == res);
    }
    return 0;
}