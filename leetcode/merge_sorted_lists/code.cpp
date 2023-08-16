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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode *res;
        if(list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        if(list1 == nullptr)
        {
            return list2;
        }
        if(list2 == nullptr)
        {
            return list1;
        }
        if(list1->val < list2->val)
        {
            res = list1;
            list1 = list1->next;
        }
        else
        {
            res = list2;
            list2 = list2->next;
        }
        ListNode *head = res;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                res->next = list1;
                res = res->next;
                list1 = list1->next;
            }
            else
            {
                res->next = list2;
                res = res->next;
                list2 = list2->next;
            }
        }
        if(list1 != nullptr)
        {
            res->next = list1;
        }
        else
        {
            res->next = list2;
        }
        return head;
    }
};

ListNode* create_list(std::vector<int> lst)
{
    if(lst.size() == 0)
    {
        return nullptr;
    }
    int i(0);
    ListNode *head = new ListNode(lst[i]);
    ListNode *runner = head;
    for(i = 1; i < lst.size(); i++)
    {
        runner->next = new ListNode(lst[i]);
        runner = runner->next;
    }
    return head;
}

void assert_equal(ListNode* first, ListNode* two)
{
    while(first != nullptr || two != nullptr)
    {
        assert(first->val == two->val);
        first = first->next;
        two = two->next;
    }
}

int main()
{

    Solution sol;
    {
        ListNode *head1 = create_list({1,2,4});
        ListNode *head2 = create_list({1,3,4});

        assert_equal(create_list({1, 1, 2, 3, 4, 4}), sol.mergeTwoLists(head1, head2));
    
    }
    {
        ListNode *head1 = create_list({});
        ListNode *head2 = create_list({});
        assert_equal(create_list({}), sol.mergeTwoLists(head1, head2));

    }
    {
        ListNode *head1 = create_list({});
        ListNode *head2 = create_list({0});
        assert_equal(create_list({0}), sol.mergeTwoLists(head1, head2));

    }
    return 0;
}