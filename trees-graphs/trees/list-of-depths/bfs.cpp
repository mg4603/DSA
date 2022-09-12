#include<vector>
#include<iostream>
using namespace std;

template <typename T, typename Q>
class LinkedList{
    struct ListNode{
        private:
            Q value;
            ListNode *next, *prev;
        public:
            ListNode(Q value){
                this->value = value;
            }
            Q getValue(){
                return this->value;
            }
            void setValue(Q value){
                this->value = value;
            }
            void setNext(ListNode* next){
                this->next = next;
            }
            ListNode* getNext(){
                return this->next;
            }
            void setPrev(ListNode* prev){
                this->prev = prev;
            }
            ListNode* getPrev(){
                return this->prev
            } 
    };
    ListNode *start, *end;
    public:
        LinkedList(){
            start = nullptr;
            end = nullptr;
        }
        Q front(){
            return start->getValue()
        }
        Q back(){
            return end->getValue();
        }
        void push_front(Q value){
            ListNode* newNode = new ListNode(value);
            if(start == nullptr && end == nullptr){
                start = newNode;
                end = newNode;
                return;
            }

            newNode->setNext(start);
            start->setPrev(newNode);
            start = newNode;
        }

        
};


int main(){
    Tree<int, int> *tree = new Tree<int, int>();
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->insert(6);
    tree->insert(7);
    tree->insert(8);
    tree->insert(9);
    tree->insert(10);
    vector<LinkedList<int, int>*> lists;
    tree->createLevelLinkedLists(lists);
    lists[0]->print();
    
    return 0;
}