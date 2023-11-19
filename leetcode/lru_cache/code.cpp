#include <iostream>
#include <assert.h>

#include <unordered_map>

class LRUCache {
    struct Node{
        Node *next;
        Node *prev;
        int val;
        int key;

        Node() : 
            key(0), val(0), prev(nullptr), next(nullptr){};

        Node(int key, int val) : 
            key(key), val(val), prev(nullptr), next(nullptr){};

        Node(int key, int val, Node *prev, Node *next) : 
            key(key), val(val), prev(prev), next(next) {};
    };
    std::unordered_map<int, Node*> mp;
    int cap;
    int size;
    Node *head;
    Node *tail;

    void addNode(Node *node)
    {
        if(size >= cap)
        {
            eraseNode(tail->key);
        }

        if(!head)
        {
            mp[node->key] = node;
            head = node;
            tail = node;
        }      
        else
        {
            node->prev = nullptr;
            node->next = head;
            head->prev = node;

            head = node;
            mp[node->key] = node;
        }      
        size++;
    }
    void eraseNode(int key)
    {
        Node *curr = mp[key];
        if(head == nullptr && tail == nullptr)
        {
            return;
        }
        else if(head == tail && tail == curr)
        {
            head = nullptr;
            tail = nullptr;
        }
        else if(curr == tail)
        {
            Node *prev = curr->prev;
            if(prev)
            {
                prev->next = nullptr;
            }
            tail = prev;
        }
        else if(head == curr)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else
        {
            if(curr && curr->prev && curr->next)
            {
                Node *prev_node = curr->prev;
                Node *next_node = curr->next;
                prev_node->next = next_node;
                next_node->prev = prev_node;
            }
        }
        mp.erase(key);
        size--;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int key) {
        if(mp.count(key))
        {
            Node *curr = mp[key];

            eraseNode(key);
            addNode(curr);
            
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            eraseNode(key);
        }
        addNode(new Node(key, value));
    }
};

int main()
{
    LRUCache obj(2);
    obj.put(1, 1);
    obj.put(2, 2);
    assert(obj.get(1) == 1);
    obj.put(3, 3);
    assert(obj.get(2) == -1);
    obj.put(4, 4);
    assert(obj.get(1) == -1);
    assert(obj.get(3) == 3);
    assert(obj.get(4) == 4);

    return 0;
}