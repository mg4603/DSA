#include <iostream>
#include <assert.h>

#include <vector>

class Employee {
public:
    int id;
    int importance;
    std::vector<int> subordinates;
};

class Solution {
    int solve(std::vector<Employee*> &employees, int id) {
        int res = employees[id]->importance;
        for(int &sub: employees[id]->subordinates) {
            res += solve(employees, sub);
        }
        return res;
    }
public:
    int getImportance(std::vector<Employee*> employees, int id) {
        std::ios::sync_with_stdio(0);
        std::vector<Employee *> mp(2001);
        for(Employee* employee: employees) {
            mp[employee->id] = employee;
        }
        return solve(mp, id);
    }
};

int main()
{
    return 0;
}