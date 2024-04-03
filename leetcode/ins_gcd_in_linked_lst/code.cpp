#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
    int gcd(int a, int b)
    {
        if(b == 0)return a;
        return gcd(b, a % b);
    }
public:
    ListNode<int>* insertGreatestCommonDivisors(ListNode<int>* head) {
        if(!head)return nullptr;
        if(!head->next)return head;
        ListNode<int> *prev = head;
        ListNode<int> *temp = head->next;
        
        while(temp)
        {
            int a = prev->val;
            int b = temp->val;
            ListNode<int> *gcdNode = new ListNode<int>(gcd(a, b), temp);
            prev->next = gcdNode;
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>{18,6,10,3});
        ListNode<int> *res = to_list(std::vector<int>{18,6,6,2,10,1,3});
        list_equal(sol.insertGreatestCommonDivisors(head), res);
    }
    return 0;
}