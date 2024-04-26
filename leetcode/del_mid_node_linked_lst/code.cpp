#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
public:
    ListNode<int>* deleteMiddle(ListNode<int>* head) {
        if(!head || !head->next)return nullptr;
        ListNode<int> *fast = head;
        ListNode<int> *slow = head;
        ListNode<int> *prev;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if(prev->next)
        {
            prev->next = prev->next->next;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>{1,3,4,7,1,2,6});
        ListNode<int> *res = to_list(std::vector<int>{1,3,4,1,2,6});
        list_equal(head, res);
    }
    return 0;
}