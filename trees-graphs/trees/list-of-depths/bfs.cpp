#include<vector>
#include<iostream>
using namespace std;

template <typename T, typename Q>
class LinkedList{
    struct ListNode{
        private:
            Q value;
            ListNode* next;
        public:
            ListNode(Q value){
                this->value = value;
            }
            
    };
    public:
        LinkedList(){

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