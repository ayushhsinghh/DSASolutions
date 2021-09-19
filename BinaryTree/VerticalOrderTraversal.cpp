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


void verticalTraversal(Node * root) {
        map<int ,vector<Node*>> mp;
        queue<pair<Node* , int>> q;
        q.push(make_pair(root , 0));
        
        while(!q.empty()){
            Node* curr = q.front().first;
            int val = q.front().second;
            q.pop();
            
            if(mp.find(val) == mp.end()){
                vector<Node*> nodes;
                nodes.push_back(curr);
                mp[val] = nodes;
            }else{
                mp[val].push_back(curr);
            }
            
            if(curr->left){
                q.push(make_pair(curr->left , val-1));
            }
             if(curr->right){
                q.push(make_pair(curr->right , val+1));
            }
    }
    for(auto it : mp){
        for(auto nodes : it.second){
            cout<<nodes->data<<endl;
        }
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

verticalTraversal(root);


return 0;
}