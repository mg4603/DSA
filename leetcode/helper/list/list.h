#ifndef LIST
#define LIST

#include <vector>

template <typename T>
struct ListNode
{
    T val;
    ListNode *next;
    ListNode();
    ListNode(T val);
    ListNode(T val, ListNode<T> *next);
};

template <typename T>
ListNode<T>* to_list(std::vector<T> vec);

template <typename T>
void list_equal(ListNode<T> *a, ListNode<T> *b);

#endif 