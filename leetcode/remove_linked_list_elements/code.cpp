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
    ListNode* removeElements(ListNode* head, int val) {
      if(head == nullptr)
      {
        return nullptr;
      }
      head->next = removeElements(head->next, val);
      return head->val == val? head->next: head;
    }
};

void assert_equal(ListNode *head1, ListNode *head2)
{
    ListNode *runner1 = head1;
    ListNode *runner2 = head2;
    while(runner1 || runner2)
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
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(6);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(4);
        head->next->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next->next = new ListNode(6);

        ListNode *head2 = new ListNode(1);
        head2->next = new ListNode(2);
        head2->next->next = new ListNode(3);
        head2->next->next->next = new ListNode(4);
        head2->next->next->next->next = new ListNode(5);
        assert_equal(sol.removeElements(head, 6), head2);
    }
    {
        ListNode *head = nullptr;
        ListNode *head2 = nullptr;

        assert_equal(sol.removeElements(head, 1), head2);
    }
    {
        ListNode *head = new ListNode(7);
        head->next = new ListNode(7);
        head->next->next = new ListNode(7);
        head->next->next->next = new ListNode(7);
       
        ListNode *head2 = nullptr;
        assert_equal(sol.removeElements(head, 7), head2);
    }
    return 0;
}