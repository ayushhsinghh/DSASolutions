#include <iostream>
#include <queue>
#include<algorithm>
#include<climits>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;


    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


bool checkBST(BinaryTreeNode<int> * root , int min=INT_MIN , int max=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    return checkBST(root->left , min , root->data -1) && checkBST(root->right ,root->data , max);
}










void printTreeByLevel(BinaryTreeNode<int> * root){
    queue<BinaryTreeNode<int>*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        BinaryTreeNode<int> *front = nodes.front();
        nodes.pop();
        cout<<front->data<<":";
        if(front->left){
            cout<<front->left->data<<",";
            nodes.push(front->left);
        }
        if(front->right){
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


    bool check = checkBST(root);

    cout<<"Tree is : "<<check;  // if output is 0 means False ; 1 : true



    return 0;
}



