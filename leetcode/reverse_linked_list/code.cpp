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
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;

        while(current != nullptr)
        {
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
        }
        head = prev;
        return head;
    }
};

void assert_equal(ListNode *head1, ListNode *head2)
{
    ListNode *runner1 = head1;
    ListNode *runner2 = head2;
    while(runner1 && runner2)
    {
        assert(runner1->val == runner2->val);
        runner1 = runner1->next;
        runner2 = runner2->next;
    }
}

int main()
{
    Solution sol;
    {
        ListNode *head1 = new ListNode(1);
        head1->next = new ListNode(2);
        head1->next->next = new ListNode(3);
        head1->next->next->next = new ListNode(4);
        head1->next->next->next->next = new ListNode(5);
        
        ListNode *head2 = new ListNode(5);
        head2->next = new ListNode(4);
        head2->next->next = new ListNode(3);
        head2->next->next->next = new ListNode(2);
        head2->next->next->next->next = new ListNode(1);
        assert_equal(sol.reverseList(head1), head2);
    }
    {
        ListNode *head1 = new ListNode(1);
        head1->next = new ListNode(2);
       
        ListNode *head2 = new ListNode(2);
        head2->next = new ListNode(1);
       
        assert_equal(sol.reverseList(head1), head2);
    }
    {
        ListNode *head1 = nullptr;
        
        ListNode *head2 = nullptr;
        
        assert_equal(sol.reverseList(head1), head2);
    }
    return 0;
}