#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"
#include <stack>

class Solution {

    int add(ListNode<int> *n1, ListNode<int> *n2, int carry)
    {
        int sum = n1->val + n2->val + carry;
        carry = sum / 10;
        n1->val = sum % 10;
        return carry;
    }
    int add(ListNode<int> *n1, int carry)
    {
        int sum = n1->val + carry;
        carry = sum / 10;
        n1->val = sum % 10;
        return carry;
    }
public:
    ListNode<int>* addTwoNumbers(ListNode<int>* l1, 
                                 ListNode<int>* l2) 
    {
        std::stack<ListNode<int>*> s1;
        std::stack<ListNode<int>*> s2;

        while(l1)
        {
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2);
            l2 = l2->next;
        }

        ListNode<int> *curr;
        ListNode<int> *prev = nullptr;
        int carry = 0;
        while(s1.size() && s2.size())
        {
            carry = add(s1.top(), s2.top(), carry);
            s2.pop();
            curr = s1.top();
            s1.pop();
            curr->next = prev;
            prev = curr;
        }

        while(s1.size())
        {
            carry = add(s1.top(), carry);
            curr = s1.top();
            s1.pop();
            curr->next = prev;
            prev = curr;
        }

        while(s2.size())
        {
            carry = add(s2.top(), carry);
            curr = s2.top();
            s2.pop();
            curr->next = prev;
            prev = curr;
        }

        if(carry)
        {
            curr = new ListNode<int>(carry);
            curr->next = prev;
        }

        return curr;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> l1 = {7,2,4,3};
        std::vector<int> l2 = {5,6,4};
        std::vector<int> res = {7,8,0,7};
        list_equal(sol.addTwoNumbers(to_list(l1), to_list(l2)), to_list(res));
    }
    {
        std::vector<int> l1 = {2,4,3};
        std::vector<int> l2 = {5,6,4};
        std::vector<int> res = {8,0,7};
        list_equal(sol.addTwoNumbers(to_list(l1), to_list(l2)), to_list(res));
    }
    {
        std::vector<int> l1 = {0};
        std::vector<int> l2 = {0};
        std::vector<int> res = {0};
        list_equal(sol.addTwoNumbers(to_list(l1), to_list(l2)), to_list(res));
    }
    return 0;
}