#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
public:
    ListNode<int>* partition(ListNode<int>* head, int x) {
        if(head == nullptr)
        {
            return nullptr;
        }
        
        ListNode<int> *small = new ListNode<int>(-1);
        ListNode<int> *small_head = small;
        ListNode<int> *large = new ListNode<int>(-1);
        ListNode<int> *large_head = large;
        
        ListNode<int> *ptr = head;
        while(ptr)
        {
            if(ptr->val < x)
            {
                small->next = ptr;
                small = small->next;
                ptr = ptr->next;
                small->next = nullptr;
            }
            else
            {
                large->next = ptr;
                large = large->next;
                ptr = ptr->next;
                large->next = nullptr;
            }
        }

        small->next = large_head->next;

        return small_head->next;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> head = {1,4,3,2,5,2};
        int x = 3;
        std::vector<int> res = {1,2,2,4,3,5};
        list_equal(sol.partition(to_list(head), x), to_list(res));
    }
    {
        std::vector<int> head = {2,1};
        int x = 2;
        std::vector<int> res = {1,2};
        list_equal(sol.partition(to_list(head), x), to_list(res));
    }
    return 0;
}