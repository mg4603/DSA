#include <iostream>
#include <assert.h>

#include <unordered_map>
#include "../helper/list/list.cpp"

class Solution {
public:
    ListNode<int>* removeZeroSumSublists(ListNode<int>* head) {
        ListNode<int> *root = new ListNode<int>(0);
        root->next = head;

        ListNode<int> *temp = head;
        std::unordered_map<int, ListNode<int>*> mp;

        int runningSum = 0;
        mp[runningSum] = root;
        while(temp)
        {
            runningSum += temp->val;
            if(mp.count(runningSum) && mp[runningSum])
            {
                int runningSum2 = runningSum;
                ListNode<int> *temp2 = mp[runningSum];
                ListNode<int> *start = temp2;

                while(temp2 != temp)
                {
                    temp2 = temp2->next;
                    runningSum2 += temp2->val;
                    if(temp2 == temp)break;
                    mp[runningSum2] = nullptr;
                }
                start->next = temp2->next;
            }
            else
            {
                mp[runningSum] = temp;
            }
            temp = temp->next;
        }
        return root->next;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *head = to_list(std::vector<int>{1,2,-3,3,1});
        ListNode<int> *res = to_list(std::vector<int>{3, 1});
        list_equal(sol.removeZeroSumSublists(head), res);
    }
    return 0;
}