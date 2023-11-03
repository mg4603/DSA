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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {

        ListNode *head = l1;
        ListNode *last = nullptr;

        int carry = 0;
        
        while(l1 != nullptr && l2 != nullptr)
        {
            l1->val += (l2->val + carry);

            carry = l1->val / 10;
            l1->val %= 10;
            
            if(l1->next == nullptr)
            {
                last = l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr)
        {
            l1->val += carry;

            carry = l1->val / 10;
            l1->val %= 10;

            if(l1->next == nullptr)
            {
                last = l1;
            }

            l1 = l1->next;
        }
    
        
        while(l2 != nullptr)
        {
            last->next = new ListNode(l2->val + carry);
            
            carry = last->next->val / 10;
            last->next->val %= 10;
            
            last = last->next;
            l2 = l2->next;
        }

        if(carry)
        {

            last->next = new ListNode(carry);
        }
        return head;
    }
};

ListNode* vecToList(std::vector<int> a)
{
    ListNode *head, *ptr;
    
    ptr = new ListNode(a[0]);
    head = ptr;

    for(int i = 1; i < a.size(); i++)
    {
        ptr->next = new ListNode(a[i]);
        ptr = ptr->next;
    }

    return head;
}

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

int main()
{
    Solution sol;
    {
        std::vector<int> l1 = {2,4,3};
        std::vector<int> l2 = {5,6,4};
        std::vector<int> res = {7, 0, 8};
        list_equal(sol.addTwoNumbers(vecToList(l1), vecToList(l2)),
                    vecToList(res));
    }
    {
        std::vector<int> l1 = {0};
        std::vector<int> l2 = {0};
        std::vector<int> res = {0};
        list_equal(sol.addTwoNumbers(vecToList(l1), vecToList(l2)),
                    vecToList(res));
    }
    {
        std::vector<int> l1 = {9,9,9,9,9,9,9};
        std::vector<int> l2 = {9,9,9,9};
        std::vector<int> res = {8,9,9,9,0,0,0,1};
        list_equal(sol.addTwoNumbers(vecToList(l1), vecToList(l2)),
                    vecToList(res));
    }
    return 0;
}