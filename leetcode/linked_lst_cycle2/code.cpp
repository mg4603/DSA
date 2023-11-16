#include <iostream>
#include <assert.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {

        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;

            slow = slow->next;
            if(fast == slow)
            {
                slow = head;
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
            

        }    
        return nullptr;
    }
};

int main()
{
    return 0;
}