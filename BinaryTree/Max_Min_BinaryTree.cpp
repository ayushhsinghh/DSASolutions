#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include <climits>
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

int maximum(BinaryTreeNode<int>* root){
    if (root==NULL) return INT_MIN; //Everything is Greater them this

    return max(root->data , max(maximum(root->left) , maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root){
    if (root==NULL) return INT_MAX; //Everything is Smaller them this

    return min(root->data , min(minimum(root->left) , minimum(root->right)));
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
    int max = maximum(root);
    int min = minimum(root);

    cout<<"Minimum is : "<<min<<endl;
    cout<<"Maximum is : "<<max<<endl;


return 0;
}