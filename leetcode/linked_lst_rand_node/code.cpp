#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"
#include <vector>
#include <algorithm>

class Solution {
    ListNode<int> *head;
    int n;
public:
    Solution(ListNode<int>* head) {
        this->head = head;
        ListNode<int> *curr = this->head;
        head = head->next;
        n = 1;
        while(head != nullptr)
        {
            curr->next = head;
            head = head->next;
            curr = curr->next;
            n++;
        }
    }
    
    int getRandom() 
    {
        int k = rand() % n;
        ListNode<int> *curr = head;
        while(k--)
        {
            curr = curr->next;
        }    
        return curr->val;
    }
};

int main()
{
    std::vector<int> list{1, 2, 3};
    Solution solution(to_list(list));
    
    assert(std::find(list.begin(), 
                     list.end(), 
                     solution.getRandom()) != list.end()); 

    assert(std::find(list.begin(), 
                     list.end(), 
                     solution.getRandom()) != list.end()); 

    assert(std::find(list.begin(), 
                     list.end(), 
                     solution.getRandom()) != list.end()); 

    assert(std::find(list.begin(), 
                     list.end(), 
                     solution.getRandom()) != list.end()); 

    assert(std::find(list.begin(), 
                     list.end(), 
                     solution.getRandom()) != list.end()); 

    return 0;
}