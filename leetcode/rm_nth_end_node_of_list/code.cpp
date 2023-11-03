#include <iostream>
#include <assert.h>

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        while(ptr1 != nullptr && n--)
        {
            ptr1 = ptr1->next;
        }
        
        if(ptr1 == nullptr)
        {
            head = head->next;
            return head;
        }

        while(ptr1 != nullptr && ptr1->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(ptr2 != nullptr && ptr2->next != nullptr)
        {
            ptr2->next = ptr2->next->next;
        }
        return head;
    }
};

void list_equal(ListNode *a, ListNode *b)
{
    if(a == nullptr && b == nullptr)
    {
        assert(true);
        return;
    }
    if(a == nullptr || b == nullptr)
    {
        assert(false);
        return;
    }
    assert(a->val == b->val);
    list_equal(a->next, b->next);
}

ListNode* to_list(std::vector<int> vec)
{
    if(vec.size() == 0)
    {
        return nullptr;
    }
    ListNode *head = new ListNode(vec[0]);
    ListNode *ptr1 = head;
    for(int i = 1; i < vec.size(); i++)
    {
        ptr1->next = new ListNode(vec[i]);
        ptr1 = ptr1->next;
    }
    return head;
}
int main()
{
    Solution sol;
    {
        std::vector<int> head = {1,2,3,4,5};
        int n = 2;
        std::vector<int> res = {1,2,3,5};
        list_equal(sol.removeNthFromEnd(to_list(head), n), to_list(res));
    }
    {
        std::vector<int> head = {1};
        int n = 1;
        std::vector<int> res = {};
        list_equal(sol.removeNthFromEnd(to_list(head), n), to_list(res));
    }
    {
        std::vector<int> head = {1,2};
        int n = 1;
        std::vector<int> res = {1};
        list_equal(sol.removeNthFromEnd(to_list(head), n), to_list(res));
    }
    return 0;
}