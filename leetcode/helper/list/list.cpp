#include "list.h"
#include <assert.h>
#include <vector>

template <typename T>
ListNode<T>::ListNode()
{
    next = nullptr;
}
template <typename T>
ListNode<T>::ListNode(T val)
{
    this->val = val;
    this->next = nullptr;
}
template <typename T>
ListNode<T>::ListNode(T val, ListNode<T> *next)
{
    this->val = val;
    this->next = next;
}


template <typename T>
ListNode<T>* to_list(std::vector<T> vec)
{
    if(vec.size() == 0)
    {
        return nullptr;
    }
    ListNode<T> *head = new ListNode<T>(vec[0]);
    ListNode<T> *ptr = head;

    for(int i = 1; i < vec.size(); i++)
    {
        ptr->next = new ListNode<T>(vec[i]);
        ptr = ptr->next;
    }
    return head;
}

template <typename T>
void list_equal(ListNode<T> *a, ListNode<T> *b)
{
    if(!a && ! b)
    {
        assert(true);
        return;
    }
    if(!a || !b)
    {
        assert(false);
        return;
    }
    assert(a->val == b->val);
    list_equal(a->next, b->next);
}
