#include <iostream>
#include <assert.h>

#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::map<ListNode*, int> visited;
        
        ListNode *runner = head;
        int pos(0);
        while(runner != nullptr)
        {
            if(visited.count(runner) == 0)
            {
                visited[runner] = pos;
                pos++;
            }
            else
            {
                return true;
            }
            runner = runner->next;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        ListNode *head = new ListNode(1);
        assert(sol.hasCycle(head) == false);
    }
    {
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = head;
        assert(sol.hasCycle(head) == true);
    }
    {
        ListNode *head = new ListNode(3);
        head->next = new ListNode(2);

        ListNode *cycle_tail = head->next;

        head->next->next = new ListNode(0);
        head->next->next->next = new ListNode(-4);
        head->next->next->next->next = cycle_tail;
        assert(sol.hasCycle(head) == true);
    }
    return 0;
}