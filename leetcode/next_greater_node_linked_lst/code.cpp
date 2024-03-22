#include <iostream>
#include <assert.h>

#include <vector>
#include "../helper/list/list.cpp"

class Solution {
public:
    std::vector<int> nextLargerNodes(ListNode<int>* head) {
        std::vector<int> res, stack;
        for(ListNode<int> *temp = head; temp; 
            temp = temp->next)res.push_back(temp->val);

        for(int i = res.size() - 1; i >= 0; i--)
        {
            int temp = res[i];
            while(!stack.empty() && 
                    stack.back() <= res[i])stack.pop_back();
            res[i] = stack.empty() ? 0 : stack.back();
            stack.push_back(temp);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>{2,1,5});
        std::vector<int> res = {5,5,0};
        assert(sol.nextLargerNodes(head) == res);
    }
    return 0;
}