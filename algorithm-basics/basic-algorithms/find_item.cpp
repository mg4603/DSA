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
                Node* getRight(){
                    return this->right;
                }
                void setValue(Q value){
                    this->value = value;
                }
                void setLeft(Node *left){
                    if(this->getLeft() != nullptr){
                        free(this->getLeft());
                    }
                    this->left = left;
                }
                void setRight(Node* right){
                    if(this->getRight() != nullptr){
                        free(this->getRight());
                    }
                    this->right = right;
                }
        };
        Node *root;     
    public:
        Tree():root(nullptr){}
        Node* getRoot(){
            return this->root;
        }
        void setRoot(Node *root){
            if(this->getRoot() != nullptr){
                free(this->getRoot());
            }
            this->root = root;
        }
};

int main(){
    return 0;
}