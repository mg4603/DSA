#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
public:
    ListNode<int>* removeNodes(ListNode<int>* head) {
        if(!head)return nullptr;
        head->next = removeNodes(head->next);
        return head->next && head->val < head->next->val ? 
                head->next : head;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list<int>(
                            std::vector<int>{5,2,13,3,8});
        ListNode<int> *res = to_list<int>(
                            std::vector<int>{13,8});
        list_equal(sol.removeNodes(head), res);
    }
    return 0;
}