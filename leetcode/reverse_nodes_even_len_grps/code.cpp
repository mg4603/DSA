#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
    ListNode<int>* reverse(ListNode<int> *head)
    {
        if(!head)return nullptr;
        ListNode<int> *prev = nullptr;
        while(head)
        {
            ListNode<int> *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    ListNode<int>* reverseEvenLengthGroups(ListNode<int>* head) {
        ListNode<int> *dummy = new ListNode<int>(0, head);

        int len = 1;
        ListNode<int> *temp = head;
        ListNode<int> *prev = dummy;
        while(temp)
        {
            ListNode<int> *tail = temp;
            ListNode<int> *nextHead = nullptr;

            int j = 1;
            while(j < len && tail && tail->next)
            {
                tail = tail->next;
                j++;
            }
            
            if(tail)nextHead = tail->next;
            
            if(j % 2 == 0)
            {
                tail->next = nullptr;
                prev->next = reverse(temp);
                prev = temp;
                temp->next = nextHead;
                temp = nextHead;
            }
            else
            {
                prev = tail;
                temp = nextHead;
            }
            len++;
        }
        return dummy->next;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(
                            std::vector<int>{5,2,6,3,9,1,7,3,8,4});
        ListNode<int> *res = to_list(
                            std::vector<int>{5,6,2,3,9,1,4,8,3,7});

        list_equal(sol.reverseEvenLengthGroups(head), res);
    }
    return 0;
}