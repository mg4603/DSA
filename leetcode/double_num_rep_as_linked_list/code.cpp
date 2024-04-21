#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
public:
    ListNode<int>* doubleIt(ListNode<int>* head) {
        if(head->val > 4)
        {
            head = new ListNode<int>(0, head);
        }

        ListNode<int> *temp = head;
        while(temp)
        {
            temp->val = (temp->val * 2) % 10;
            if(temp->next && temp->next->val > 4)
            {
                temp->val++;
            }

            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>{1,8,9});
        ListNode<int> *res = to_list(std::vector<int>{3,7,8});
        list_equal(sol.doubleIt(head), res);
    }
    return 0;
}