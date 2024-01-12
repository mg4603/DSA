#include <iostream>
#include <assert.h>

#include <stack>
#include <vector>
#include <sstream>

class Solution {
    struct Log{
        int id;
        std::string status;
        int timestamp;
    };
public:
    std::vector<int> exclusiveTime(int n, 
                    std::vector<std::string>& logs) {
        std::vector<int> res(n);
        std::stack<Log> st;

        for(std::string log: logs)
        {
            std::string id;
            std::string status;
            std::string timestamp;
            std::stringstream ss(log);
            getline(ss, id, ':');
            getline(ss, status, ':');
            getline(ss, timestamp, ':');

            Log curr = {std::stoi(id), status, std::stoi(timestamp)};

            if(curr.status == "start")
            {
                st.push(curr);
            }
            else
            {
                Log top = st.top();
                st.pop();
                int time_added = curr.timestamp - top.timestamp + 1;
                res[curr.id] += time_added;

                if(!st.empty())
                {
                    res[st.top().id] -= time_added;
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
        int n = 2;
        std::vector<std::string> logs = {"0:start:0","1:start:2",
                                         "1:end:5","0:end:6"};
        std::vector<int> res = {3, 4};
        assert(sol.exclusiveTime(n, logs) == res);
    }
    return 0;
}