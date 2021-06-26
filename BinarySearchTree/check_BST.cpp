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


class Triplate{
    public:
    bool isBST;
    int minimum;
    int maximum;
};


Triplate checkBST(BinaryTreeNode<int> *root){
    if(root==NULL){
        Triplate t;
        t.isBST = true;
        t.minimum = INT_MAX;
        t.maximum = INT_MIN;
        return t;
    }
    Triplate leftSide = checkBST(root->left);
    Triplate rightSide = checkBST(root->right);

    int minimum = min(root->data , min(leftSide.minimum , rightSide.minimum));
    int maximum = max(root->data , max(leftSide.maximum , rightSide.maximum));

    bool output = (root->data > leftSide.maximum) && (root->data < rightSide.minimum) && leftSide.isBST && rightSide.isBST;
    Triplate t;
    t.isBST = output;
    t.minimum = minimum;
    t.maximum = maximum;

    return t;
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

    Triplate t = checkBST(root);

    cout<<"Tree is : "<<t.isBST; // output 0 means false , 1 : true




    return 0;
}



