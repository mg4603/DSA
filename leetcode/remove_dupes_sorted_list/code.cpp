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
        if(head == nullptr)
        {
            return head;
        }
        ListNode* runner = head;
        while(runner->next != nullptr)
        {
            if(runner->val == runner->next->val)
            {
                runner->next = runner->next->next;
                continue;
            }
            runner = runner->next;
        }
        return head;
    }
};

void assert_equal(ListNode* head1, ListNode *head2)
{
    while(head1 != nullptr && head2 != nullptr)
    {
        assert(head1->val == head2->val);
        head1 = head1->next;
        head2 = head2->next;
    }
}

int main()
{
    Solution sol;
    {
        ListNode *head = new ListNode(1);
        ListNode *runner = head;
        runner->next = new ListNode(2);
        runner = runner->next;
        runner->next = new ListNode(2);

        ListNode *head2 = new ListNode(1);
        runner = head2;
        runner->next = new ListNode(2);
        assert_equal(sol.deleteDuplicates(head), head2);
    }
    {

        ListNode *head = new ListNode(1);
        ListNode *runner = head;
        runner->next = new ListNode(1);
        runner = runner->next;
        runner->next = new ListNode(2);
        runner = runner->next;
        runner->next = new ListNode(3);
        runner = runner->next;
        runner->next = new ListNode(3);

        ListNode *head2 = new ListNode(1);
        runner = head2;
        runner->next = new ListNode(2);
        runner = runner->next;
        runner->next = new ListNode(3);
        assert_equal(sol.deleteDuplicates(head), head2);
    }
    return 0;
}