#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
    ListNode<int>* merge(ListNode<int> *h1, ListNode<int> *h2)
    {
        ListNode<int> *new_head;

        if(h1->val < h2->val)
        {
            new_head = h1;
            h1 = h1->next;
        }
        else
        {
            new_head = h2;
            h2 = h2->next;
        }

        ListNode<int> *ptr = new_head;
        
        while(h1 && h2)
        {
            if(h1->val < h2->val)
            {
                ptr->next = h1;
                h1 = h1->next;
            }
            else
            {
                ptr->next = h2;
                h2 = h2->next;
            }
            ptr = ptr->next;
        }

        while(h1)
        {
            ptr->next = h1;
            h1 = h1->next;
            ptr = ptr->next;
        }
        while(h2)
        {
            ptr->next = h2;
            h2 = h2->next;
            ptr = ptr->next;
        }
        return new_head;
    }

public:
    ListNode<int>* sortList(ListNode<int>* head) 
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        ListNode<int> *fast = head->next;
        ListNode<int> *slow = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode<int> *h2 = slow->next;
        slow->next = nullptr;

        head = sortList(head);
        h2 = sortList(h2);
        return merge(head, h2);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> head = {4,2,1,3};
        std::vector<int> res = {1,2,3,4};
        list_equal(sol.sortList(to_list(head)), to_list(res));
    }
    {
        std::vector<int> head = {-1,5,3,4,0};
        std::vector<int> res = {-1,0,3,4,5};
        list_equal(sol.sortList(to_list(head)), to_list(res));
    }
    {
        std::vector<int> head = {};
        std::vector<int> res = {};
        list_equal(sol.sortList(to_list(head)), to_list(res));
    }
    return 0;
}