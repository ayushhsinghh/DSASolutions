#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;


template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};


BinaryTreeNode<int>* mirrorTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return NULL;
    }


    if(root->left)  mirrorTree(root->left);
    if(root->right)  mirrorTree(root->right);

    
    if(root->left && root->right){
        // To swap left data and right data
        BinaryTreeNode <int>* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    return root;
}


void printTreeByLevel(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> nodes;
    nodes.push(root);
    while(nodes.size() != 0){
        BinaryTreeNode<int>* front = nodes.front();
        nodes.pop();
        cout<<front->data<<":";
        if(front->left != NULL){
            cout<<front->left->data<<",";
            nodes.push(front->left);
        }
        if(front->right != NULL){
            cout<<front->right->data<<",";
            nodes.push(front->right);
        }
        cout<<endl; 
    }
}

int main(){
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(8);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(12);
    BinaryTreeNode<int> *node3 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int> *node4 = new BinaryTreeNode<int>(9);
    BinaryTreeNode<int> *node5 = new BinaryTreeNode<int>(11);
    BinaryTreeNode<int> *node6 = new BinaryTreeNode<int>(13);
    // BinaryTreeNode<int> *node7 = new BinaryTreeNode<int>(2);


    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    // node6->right = node7;


    printTreeByLevel(root);

    cout<<"End"<<endl;

    BinaryTreeNode<int> *mirror = mirrorTree(root);

    printTreeByLevel(mirror);


return 0;
}