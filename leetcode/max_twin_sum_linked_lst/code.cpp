#include <iostream>
#include <assert.h>


#include "../helper/list/list.cpp"
#include <stack>

class Solution {
public:
    int pairSum(ListNode<int>* head) {
        ListNode<int> *fast = head;
        ListNode<int> *slow = head;

        std::stack<ListNode<int> *> st;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            st.push(slow);
            slow = slow->next;
        }

        int res = 0;
        while(slow)
        {
            res = std::max(res, st.top()->val + slow->val);
            st.pop();
            slow = slow->next;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>{5,4,2,1});
        int res = 6;
        assert(sol.pairSum(head) == res);
    }
    return 0;
}