#include<iostream>
using namespace std;

template<typename Q>
class Tree{
    private:
        class Node{
            private:
                Q value;
                Node *left, *right;
            public:
                Node(Q value): left(nullptr), right(nullptr){
                    this->value = value;
                }
                Q getValue(){
                    return this->value;
                }
                Node* getLeft(){
                    return this->left;
                }
        };
        Node *root;     
    public:
        Tree():root(nullptr){}
};

int main(){
    return 0;
}