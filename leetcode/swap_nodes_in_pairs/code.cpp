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
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr && curr->next)
        {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;

            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};

ListNode* to_list(std::vector<int> vec)
{
    if(vec.size() == 0)
    {
        return nullptr;
    }
    ListNode * head = new ListNode(vec[0]);
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
    if(a == nullptr && b == nullptr)
    {
        assert(true);
        return;
    }
    else if(a == nullptr || b == nullptr)
    {
        assert(false);
        return;
    }
    assert(a->val == b->val);
    list_equal(a->next, b->next);
}

int main()
{
    Solution sol;
    {
        std::vector<int> vec = {1,2,3,4};
        std::vector<int> res = {2,1,4,3};
        list_equal(sol.swapPairs(to_list(vec)), to_list(res));
    }
    {
        std::vector<int> vec = {};
        std::vector<int> res = {};
        list_equal(sol.swapPairs(to_list(vec)), to_list(res));
    }
    {
        std::vector<int> vec = {1};
        std::vector<int> res = {1};
        list_equal(sol.swapPairs(to_list(vec)), to_list(res));
    }
    return 0;
}