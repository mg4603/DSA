#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
public:
    void deleteNode(ListNode<int>* node) 
    {
        ListNode<int>* del_node = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete del_node;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>({4,5,1,9}));
        ListNode<int> *del_node = head->next;

        ListNode<int> *res = to_list(std::vector<int>({4,1,9}));

        sol.deleteNode(del_node);
        list_equal(head, res);
    }
    {
        ListNode<int> *head = to_list(std::vector<int>({4,5,1,9}));
        ListNode<int> *del_node = head->next->next;

        ListNode<int> *res = to_list(std::vector<int>({4,5,9}));

        sol.deleteNode(del_node);
        list_equal(head, res);
    }
    return 0;
}