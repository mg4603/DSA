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
        };
        Node *root;
    public:
        Tree():root(nullptr){}
};

int main(){
    return 0;
}