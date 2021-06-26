#include <iostream>
#include <queue>
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


void printRange(BinaryTreeNode<int>*  root, int min , int max){
    if (root==NULL){
        return;
    }

    
    if(root->data >= min && root->data <= max){
        cout<<root->data<<endl;
    }
    if(root->data>min){
        printRange(root->left , min , max);
    }
    if(root->data<max){
        printRange(root->right , min , max);
    }
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


    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    printTreeByLevel(root);

    printRange(root , 8 , 12);



    return 0;
}



