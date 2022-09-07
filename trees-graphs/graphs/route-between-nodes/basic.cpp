#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

enum State{
    Unvisited, Visited, Visiting
};

template <typename Q>
struct Node{
    Q value;
    vector<Node*> adjacentNodes;
    public:
        Node(Q value){
            this->value = value;
        }
        void addAdjacentNode(Node<Q>* node){
            this->adjacentNodes.push_back(node);
        }
        void getAdjacentNodes(){
            return this->adjacentNodes;
        }

};

template<typename Q>
class Graph{
    vector<Node<Q>*> nodes;
    public:
        Graph(){}
        void addNode(Node* node){
            this->nodes.push_back(node);
        }

        void connectNodes(Node<Q>* node1, Node<Q>* node2){
            node1->addAdjacentNode(node2);
            node2->addAdjacentNode(node1);
        }
        // uses bfs
        bool checkIfConnected(Node<Q>* node1, Node<Q>* node2){

            map<Node<Q>*, State> visitState;
            if(node1 == node2){return true;}
            queue<Node<Q>*> queue;
            queue.push(node1);
            while(!queue.empty()){
                Node<Q>* node = queue.pop();
                for(Node<Q>* adjNode: node->adjacentNodes){
                    if(visitState.find(adjNode) == visitState.end()){
                        visitState.insert(pair<Node*, State>(adjNode, State.Visited));
                        queue.push(adjNode);
                    }else{
                        if(adjNode == node2){
                            return true;
                        }
                    }
                    
                }
            }
            return false;
        }
};  


int main(){
    return 0;
}