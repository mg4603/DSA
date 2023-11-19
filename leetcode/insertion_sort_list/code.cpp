#include <iostream>
#include <assert.h>

#include <limits>
#include "../helper/list/list.cpp"

class Solution {
public:
    ListNode<int>* insertionSortList(ListNode<int>* head) 
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        ListNode<int> *new_head = new ListNode<int>(0);
        ListNode<int> *res_ptr = new_head;

        while(head)
        {
            ListNode<int> *least_prev = nullptr;
            ListNode<int> *least = nullptr;
            int least_val = std::numeric_limits<int>::max();

            ListNode<int> *ptr = head;
            ListNode<int> *prev = nullptr;

            
            while(ptr)
            {
                if(ptr->val < least_val)
                {
                    least_val = ptr->val;
                    least = ptr;
                    least_prev = prev;
                }
                prev = ptr;
                ptr = ptr->next;
            }

            if(!least_prev)
            {
                head = head->next;
            }
            else
            {
                least_prev->next = least->next;
            }


            if(res_ptr && least)
            {
                res_ptr->next = least;
                least->next = nullptr;
                res_ptr = res_ptr->next;
            }

        }
        return new_head->next;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> head = {4,2,1,3};
        std::vector<int> res = {1,2,3,4};
        list_equal(sol.insertionSortList(to_list(head)), to_list(res));
    }
    {
        std::vector<int> head = {-1,5,3,4,0};
        std::vector<int> res = {-1,0,3,4,5};
        list_equal(sol.insertionSortList(to_list(head)), to_list(res));
    }
    return 0;
}