#include<iostream>
using namespace std;

template <typename T, typename Q>
class Tree{
    private:
        class Node{
            private:
                Q value;
                Node* left;
                Node* right;
            public:
                Node(Q value):left(nullptr):right(nullptr){
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
                void setLeft(Node* left){
                    if(this->getLeft() != nullptr){
                        free(this->getLeft());
                    }
                    this->left = left;
                }
                void setRight(Node* right){
                    if(this.getRight() != nullptr){
                        free(this.getRight());
                    }
                    this->right = right;
                }
        };

        Node *root;
    public:
        Tree():root(nullptr){}
        Node* getRoot(){
            if(this->root == nullptr)
            {
                throw "Tree empty";
            }
            return this->root;
        }
        void setRoot(Node* root){
            if(this->getRoot() != nullptr){
                free(this->getRoot());
            }
            this->root = root;
        }
        void insert(Q value){
            Node *newNode = new Node(value);
            if(this->getRoot() == nullptr){
                this->setRoot(newNode);
                return;
            }
            Node *ptr = this->getRoot();
            Node *prevPtr;
            while(ptr != nullptr){
                prevPtr = ptr;
                if(ptr->getValue() < value){
                    ptr = ptr->getRight();
                }else{
                    ptr = ptr->getLeft();
                }
            }

            if(prevPtr->getValue() < value){
                prevPtr->setRight(newNode);
            }else{
                prevPtr->setLeft(newNode);
            }
        }
};

int main(){
    return 0;
}