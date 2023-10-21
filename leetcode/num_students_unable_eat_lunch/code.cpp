#include <iostream>
#include <assert.h>

#include <queue>
#include <vector>

class Solution {
public:
    int countStudents(std::vector<int>& students, 
                      std::vector<int>& sandwiches) 
    {
        std::queue<int> q_sandwiches;
        std::queue<int> q_students;
        for(int i = 0; i < students.size(); i++)
        {
            q_sandwiches.push(sandwiches[i]);
            q_students.push(students[i]);
        }
        int n = 0;
        while(!q_sandwiches.empty())
        {
            if(q_sandwiches.front() == q_students.front())
            {
                q_sandwiches.pop();
                q_students.pop();
                n = 0;
            }
            else
            {
                q_students.push(q_students.front());
                q_students.pop();
                n++;
            }
            if(n == q_students.size())
            {
                break;
            }
        }
        return q_students.size();
    }
};

int main()
{
    Solution sol;
    {
         std::vector<int> students = {1,1,0,0};
         std::vector<int> sandwiches = {0,1,0,1};
        int res = 0;
        assert(sol.countStudents(students, sandwiches) == res);
    }
    {
         std::vector<int> students = {1,1,1,0,0,1};
         std::vector<int> sandwiches = {1,0,0,0,1,1};
        int res = 3;
        assert(sol.countStudents(students, sandwiches) == res);
    }
    return 0;
}