#include <iostream>
#include <assert.h>

#include <vector>
#include "../helper/list/list.h"



class Solution {
public:
    std::vector<ListNode<int>*> splitListToParts(ListNode<int>* head, int k) {
        int len = 0;
        ListNode<int> *temp = head;
        while(temp)
        {
            temp = temp->next;
            len++;
        }

        int extra = len % k;
        temp = head;
        std::vector<ListNode<int>*> res;
        while(temp)
        {
            res.push_back(temp);

            int curr_len = 1;
            while(curr_len < len / k)
            {
                temp = temp->next;
                curr_len++;
            }

            if(extra > 0 && len > k)
            {
                temp = temp->next;
                extra--;
            }

            ListNode<int> *temp2 = temp->next;
            temp->next = nullptr;
            temp = temp2;
        }

        while(len < k)
        {
            res.push_back(nullptr);
            len++;
        }
        return res;
    }
};

int main()
{
    return 0;
}