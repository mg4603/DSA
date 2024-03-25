#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"

class Solution {
public:
    ListNode<int>* mergeInBetween(ListNode<int>* list1, 
                                    int a, int b, 
                                    ListNode<int>* list2) {
        ListNode<int> *temp = list1;

        while(a-- > 1)
        {
            b--;
            temp = temp->next;
        }

        ListNode<int> *temp2 = temp->next;
        while(b--)
        {
            temp2 = temp2->next;
        }

        temp->next = list2;

        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = temp2;
        return list1;
    }
};

int main()
{
    Solution sol;
    {
        ListNode<int> *list1 = to_list(
                            std::vector<int>{
                                10,1,13,6,9,5});
        int a = 3;
        int b = 4;
        ListNode<int> *list2 = to_list(
                            std::vector<int>{
                                1000000,1000001,
                                1000002});

        ListNode<int> *res = to_list(
                            std::vector<int>{
                                10,1,13,1000000,
                                1000001,1000002,5});
        list_equal(sol.mergeInBetween(list1, a, b, list2), res);
    }
    return 0;
}