#include <iostream>
#include <assert.h>

#include <vector>
#include <climits>
#include "../helper/list/list.cpp"

class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode<int>* head) {
        ListNode<int> *prev = head;
        ListNode<int> *curr = head->next;

        std::vector<int> idx;
        int i = 1;
        while(curr->next)
        {
            if((prev->val < curr->val && curr->val > curr->next->val) || 
                (prev->val > curr->val && curr->val < curr->next->val))
            {
                idx.push_back(i);
            }
            i++;
            prev = curr;
            curr = curr->next;
        }

        if(idx.size() < 2)return {-1, -1};

        std::vector<int> res{INT_MAX, idx.back() - idx.front()};

        for(int i = 1; i < idx.size(); i++)
        {
            res[0] = std::min(res[0], idx[i] - idx[i - 1]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>{5,3,1,2,5,1,2});
        std::vector<int> res = {1, 3};
        assert(sol.nodesBetweenCriticalPoints(head) == res);
    }
    return 0;
}