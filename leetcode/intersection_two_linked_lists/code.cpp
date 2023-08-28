#include <iostream>
#include <assert.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA(1);
        int lenB(1);
        ListNode *runnerA = headA;
        while(runnerA->next != nullptr)
        {
            lenA++;
            runnerA = runnerA->next;
        }

        ListNode *runnerB = headB;
        while(runnerB->next != nullptr)
        {
            lenB++;
            runnerB = runnerB->next;
        }

        if(runnerA != runnerB)
        {
            return nullptr;
        }

        runnerA = headA;
        runnerB = headB;
        
        if(lenA > lenB)
        {
            while(lenA > lenB)
            {
                runnerA = runnerA->next;
                lenA--;
            }
        }
        else if(lenB > lenA)
        {
            while(lenB > lenA)
            {
                runnerB = runnerB->next;
                lenB--;
            }
        }
        while(runnerA && runnerB)
        {
            if(runnerA == runnerB)
            {
                return runnerA;
            }
            runnerA = runnerA->next;
            runnerB = runnerB->next;
        }
        return nullptr;
    }
};

int main()
{
    Solution sol;
    {
        ListNode *headA = new ListNode(4);
        headA->next = new ListNode(1);
        headA->next->next = new ListNode(8);
        headA->next->next->next = new ListNode(4);
        headA->next->next->next->next = new ListNode(5);


        ListNode *headB = new ListNode(5);
        headB->next = new ListNode(6);
        headB->next->next = new ListNode(1);
        headB->next->next->next = headA->next->next;

        ListNode *resNode = headA->next->next;

        assert(sol.getIntersectionNode(headA, headB) == resNode);
    }
    {
        ListNode *headA = new ListNode(1);
        headA->next = new ListNode(9);
        headA->next->next = new ListNode(1);
        headA->next->next->next = new ListNode(2);
        headA->next->next->next->next = new ListNode(4);


        ListNode *headB = new ListNode(3);

        headB->next = headA->next->next->next;

        ListNode *resNode = headA->next->next->next;

        assert(sol.getIntersectionNode(headA, headB) == resNode);
    }
    {
        ListNode *headA = new ListNode(2);
        headA->next = new ListNode(6);
        headA->next->next = new ListNode(4);


        ListNode *headB = new ListNode(1);
        headB->next = new ListNode(5);

        ListNode *resNode = nullptr;

        assert(sol.getIntersectionNode(headA, headB) == resNode);
    }
    return 0;
}