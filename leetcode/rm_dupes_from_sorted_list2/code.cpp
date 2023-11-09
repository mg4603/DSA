#include <iostream>
#include <assert.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }

        while(head && head->next && head->next->val == head->val)
        {
            while(head->next && head->val == head->next->val)
            {
                head = head->next;
            }
            head = head->next;
        }

        if(!head)
        {
            return nullptr;
        }

        ListNode *prev_node = head;
        ListNode *ptr = head->next;

        while(ptr)
        {
            if(ptr->next && ptr->next->val == ptr->val)
            {
                while(ptr->next && ptr->val == ptr->next->val)
                {
                    ptr = ptr->next;
                }
                ptr = ptr->next;
                if(ptr && ptr->next && ptr->next->val == ptr->val)
                {
                    continue;
                }
                prev_node->next = ptr;
                prev_node = ptr;
            }
            else
            {
                prev_node = ptr;
                ptr = ptr->next;
            }            
        }
        return head;
        
    }
};

int main()
{
    Solution sol;
    return 0;
}