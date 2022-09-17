#include<iostream>
#include<vector>
using namespace std;

template <typename T, typename Q>
class BinaryTree{
    private:
        class Node{
            private:
                Q value;
                Node* left;
                Node* right;
            public:
                Node(Q value){
                    this->value = value;
                }
                void setValue(Q value){
                    this->value = value;
                }
                void setLeft(Node* left){
                    if(this->left != nullptr){
                        free(this->left);
                    }
                    this->left = left;
                }
                void setRight(Node* right){
                    if(this->right != nullptr){
                        free(this->right);
                    }
                    this->right = right;
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
        };
        void inorderPrint(Node *root){
            if(root != nullptr){
                inorderPrint(root->getLeft());
                cout<<root->getValue()<<" ";
                inorderPrint(root->getRight());
            }
        }

        void inorderList(Node* root, vector<Q> &vec){
            if(root != nullptr){
                inorderList(root->getLeft(), vec);
                vec.push_back(root->getValue());
                inorderList(root->getRight(), vec);
            }
        }   

        vector<Q> inorderList(){
            vector<Q> vec;
            inorderList(this->getRoot(), vec);
            return vec;
        }

        Node *root;
    public:
        BinaryTree():root(nullptr){}
        void setRoot(Node *root){
            if(this->root != nullptr){
                free(this->root);
            }
            this->root = root;
        }
        Node* getRoot(){
            return this->root;
        }

        void inorderPrint(){
            inorderPrint(this->getRoot());
        }

        void insert(Q value){
            Node *newNode = new Node(value);
            if(root == nullptr){
                this->setRoot(newNode);
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
            cout<<value<<endl;
            if(prevPtr->getValue() < value){
                prevPtr->setRight(newNode);
            }else{
                prevPtr->setLeft(newNode);
            }

        }

        bool validateBST(){
            vector<Q> vec = this->inorderList();
            for(T i(0); i < vec.size()-1; i++){
                if(vec.at(i) > vec.at(i+1)){
                    return false;
                }
            }
            return true;
        }        

};

int main(){
    BinaryTree<int, int> *tree = new BinaryTree<int, int>();
    tree->insert(2);
    tree->insert(1);
    tree->insert(3);
    cout<<tree->validateBST();
    return 0;
}