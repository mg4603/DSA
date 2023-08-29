#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> vals;
        ListNode *runner = head;
        while(runner)
        {
            vals.push_back(runner->val);
            runner = runner->next;
        }
        std::reverse(vals.begin(), vals.end());
        runner = head;
        int i(0);
        while(runner)
        {
            if(runner->val != vals[i++])
            {
                return false;
            }
            runner = runner->next;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(1);
        assert(sol.isPalindrome(head) == true);
    }
    {
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        assert(sol.isPalindrome(head) == false);
    }
    return 0;
}