#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"
#include <vector>
#include <unordered_set>

class Solution {
public:
    int numComponents(ListNode<int>* head, std::vector<int>& nums) {
        std::unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;

        ListNode<int> *temp = head;
        while(temp)
        {
            if(st.count(temp->val) && 
                !(temp->next && st.count(temp->next->val)))res++;
            temp = temp->next;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>{0,1,2,3});
        std::vector<int> nums = {0,1,3};
        int res = 2;
        assert(sol.numComponents(head, nums) == res);
    }
    return 0;
}