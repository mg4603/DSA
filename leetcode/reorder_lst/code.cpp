#include <iostream>
#include <assert.h>

#include <vector>
#include <assert.h>
#include "../helper/list/list.cpp"

class Solution {
public:
    void reorderList(ListNode<int>* head) 
    {        
        if(!head)
        {
            return;
        }

        ListNode<int> *slow = head;
        ListNode<int> *fast = head->next;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode<int> *tail = nullptr;
        ListNode<int> *h2 = slow->next;
        slow->next = nullptr;
        
        while(h2)
        {
            ListNode<int> *temp = h2->next;
            h2->next = tail;
            tail = h2;

            h2 = temp;
        }

        ListNode<int> *h1 = head;
        h2 = tail;
        while(h2)
        {
            ListNode<int> *temp1;
            temp1 = h1->next; 
            ListNode<int> *temp2;
            temp2 = h2->next;

            h1->next = h2;
            h2->next = temp1;

            h1 = temp1;
            h2 = temp2;
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> vec = {1,2,3,4};
        std::vector<int> res = {1,4,2,3};
        
        ListNode<int> *head = to_list(vec);

        sol.reorderList(head);
        list_equal(head, to_list(res));
    }
    {
        std::vector<int> vec = {1,2,3,4,5};
        std::vector<int> res = {1,5,2,4,3};
        
        ListNode<int> *head = to_list(vec);

        sol.reorderList(head);
        list_equal(head, to_list(res));
    }
    return 0;
}