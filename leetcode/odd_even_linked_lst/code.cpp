#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"
class Solution {
public:
    ListNode<int>* oddEvenList(ListNode<int>* head) 
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }    

        ListNode<int> *odd = head;
        ListNode<int> *even = head->next;
        ListNode<int> *even_head = even;
        ListNode<int> *curr = head->next->next;
        
        int cur_cnt = 3;
        
        while(curr)
        {
            if(cur_cnt % 2 == 1)
            {
                odd->next = curr;
                odd = odd->next;
            }
            else
            {
                even->next = curr;
                even = even->next;
            }
            cur_cnt++;
            curr = curr->next;
        }

        odd->next = even_head;
        even->next = nullptr;
        
        return head;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>({1,2,3,4,5}));
        ListNode<int> *res = to_list(std::vector<int>({1,3,5,2,4}));
        list_equal(sol.oddEvenList(head), res);
    }
    {
        ListNode<int> *head = to_list(std::vector<int>({2,1,3,5,6,4,7}));
        ListNode<int> *res = to_list(std::vector<int>({2,3,6,7,1,5,4}));
        list_equal(sol.oddEvenList(head), res);
    }
    return 0;
}