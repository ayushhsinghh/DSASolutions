#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<utility>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

/*
                1
               / \
              2  3
             /\ /\
            4 5 6 7


 */ 


void topView(Node * root) {
        map<int, Node*> _map;
        queue<pair<Node* , int>> myQ;
        myQ.push(make_pair(root, 0));
        
        while(myQ.size()){
            Node* node = myQ.front().first;
            int val = myQ.front().second;
            myQ.pop();
            if(_map.find(val) == _map.end()){
                _map[val] = node;
            }
            
            if(node->left){
                myQ.push(make_pair(node->left, val - 1));
            }
            if(node->right){
                 myQ.push(make_pair(node->right, val + 1));
            }
        }
        for(auto it: _map){
            cout<<it.second->data<<" ";
        }

}


int main(){
Node* root = new Node(10);
Node* node1 = new Node(5);
Node* node2 = new Node(15);
Node* node3 = new Node(1);
Node* node4 = new Node(7);
Node* node5 = new Node(13);
Node* node6 = new Node(18);

root->left = node1;
root->right = node2;
node1->left = node3;
node1->right = node4;
node2->left = node5;
node2->right = node6;

topView(root);


return 0;
}