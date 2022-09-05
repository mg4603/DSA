#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename Q>
struct Node{
    Q value;
    vector<Node*> adjacentNodes;
    public:
        Node(Q value){
            this->value = value;
        }
};



int main(){
    return 0;
}