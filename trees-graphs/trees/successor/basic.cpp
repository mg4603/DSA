#include<iostream>
using namespace std;

template <typename T, typename Q>
class Tree{
    private:
        class Node{
            private:
                Q value;
                Node *left,
                    *right,
                    *parent;
            public:
                Node(Q value):left(nullptr), right(nullptr), parent(nullptr){
                    this->value = value;
                }
                void setValue(Q value){
                    this->value = value;
                }

                void setLeft(Node *left){
                    this->left = left;
                }
                
                void setRight(Node* right){
                    if(this->getRight() != nullptr){
                        free(this->getRight());
                    }
                    this->right = right;
                }

                Q getValue(){
                    return this->value;
                }
        };
        Node *root;
    public:
        Tree():root(nullptr){}
};

int main(){
    return 0;
}