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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;

        while(k-- )
        {
            if(ptr1 != nullptr && ptr1->next != nullptr)
            {
                ptr1 = ptr1->next;
            }
            else
            {
                ptr1 = head;
            }
        }

        while(ptr1 != nullptr && ptr1->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ListNode *new_head = nullptr;
        if(ptr2 != nullptr && ptr2->next != nullptr)
        {
            new_head = ptr2->next;
            ptr2->next = nullptr;
            ptr1->next = head;
        }
        else if(ptr2 != nullptr)
        {
            return head;
        }
        
        return new_head;
    }
};

ListNode* to_list(std::vector<int> vec)
{
    if(vec.size() == 0)
    {
        return nullptr;
    }
    ListNode *head = new ListNode(vec[0]);
    ListNode *ptr = head;
    for(int i = 1; i < vec.size(); i++)
    {
        ptr->next = new ListNode(vec[i]);
        ptr = ptr->next;
    }
    return head;
}

void list_equal(ListNode *a, ListNode *b)
{
    if(!a && !b)
    {
        assert(true);
        return;
    }
    else if(!a || !b)
    {
        assert(false);
        return;
    }
    list_equal(a->next, b->next);
}

int main()
{
    Solution sol;
    {
        std::vector<int> head = {1,2,3,4,5};
        int k = 2;
        std::vector<int> res = {4,5,1,2,3};
        list_equal(sol.rotateRight(to_list(head), k), to_list(res));
    }
    {
        std::vector<int> head = {0,1,2};
        int k = 4;
        std::vector<int> res = {2,0,1};
        list_equal(sol.rotateRight(to_list(head), k), to_list(res));
    }
    return 0;
}