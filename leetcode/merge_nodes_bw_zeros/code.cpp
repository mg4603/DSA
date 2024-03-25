#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
public:
    ListNode<int>* mergeNodes(ListNode<int>* head) {
        if(!head)return nullptr;
        if(!head->next)return head;

        ListNode<int> *start = head;
        ListNode<int> *runner = head->next;

        int runningSum = 0;
        while(runner && runner->next)
        {
            if(runner->val == 0)
            {
                start->val = runningSum;
                runningSum = 0;
                start->next = runner;
                start = runner;
            }
            else
            {
                runningSum += runner->val;
            }
            runner = runner->next;
        }
        start->val = runningSum;
        start->next = nullptr;
        return head;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>{0,3,1,0,4,5,2,0});
        ListNode<int> *res = to_list(std::vector<int>{4, 11});
        list_equal(sol.mergeNodes(head), res);
    }
    return 0;
}