#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
public:
    ListNode<int>* swapNodes(ListNode<int>* head, int k) {
        ListNode<int> *begin = head;
        int cnt = 1;
        while(begin && cnt < k)
        {
            begin = begin->next;
            cnt++;
        }

        if(!begin)
        {
            return head;
        }

        ListNode<int> *end = head;
        ListNode<int> *temp = begin;
        while(temp && temp->next)
        {
            temp = temp->next;
            end = end->next;
        }
        int val = begin->val;
        begin->val = end->val;
        end->val = val;
        return head;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>{1,2,3,4,5});
        int k = 2;
        ListNode<int> *res = to_list(std::vector<int>{1,4,3,2,5});
        list_equal(sol.swapNodes(head, k), res);
    }
    return 0;
}