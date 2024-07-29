#include <iostream>
#include <assert.h>

#include <unordered_set>
#include "../helper/list/list.cpp"
#include <vector>

class Solution {
public:
    ListNode<int>* modifiedList(std::vector<int>& nums, ListNode<int>* head) {
        std::unordered_set<int> st(nums.begin(), nums.end());

        while(head && st.count(head->val)) {
            head = head->next;
        }
        
        ListNode<int> *prev = new ListNode<int>(0, head);
        head = prev;
        ListNode<int> *temp = head->next; 
        while(temp) {
            if(st.count(temp->val)) {
                if(temp->next)prev->next = temp->next;
                else prev->next = nullptr;
                temp = temp->next;
                continue;
            }
            prev = temp;
            temp = temp->next;
        }
        return head->next;;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1, 2, 3};
        ListNode<int> *head = to_list<int>(std::vector<int>{1,2,3,4,5});
        ListNode<int> *res = to_list<int>(std::vector<int>{4, 5});
        list_equal(res, sol.modifiedList(nums, head));
    }
    return 0;
}