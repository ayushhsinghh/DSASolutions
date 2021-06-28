#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;


    BinaryTreeNode(T data){
        this->data = data;
        left  = NULL;
        right  = NULL;
    }
    
    };


vector<int>* pathRootToNode(BinaryTreeNode<int>* root , int num){
    if (root == NULL){
        return NULL;
    }


    if(root->data == num){ //element found create vector and return it.
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> * leftSide = pathRootToNode(root->left , num);
    if(leftSide != NULL){ //execute only if element is found in leftSide
        leftSide->push_back(root->data);
        return leftSide;
    }

    vector<int> * rightSide = pathRootToNode(root->right , num);
    if(rightSide != NULL){ //execute only if element is found in RightSide
        rightSide->push_back(root->data);
        return rightSide;
    }
    else{
        return NULL;
    }
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
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int> *node3 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int> *node4 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int> *node5 = new BinaryTreeNode<int>(6);
    BinaryTreeNode<int> *node6 = new BinaryTreeNode<int>(7);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    printTreeByLevel(root);

    cout<<"Path is ";

    vector<int>* output = pathRootToNode(root , 7);

    for(int i = 0; i < output->size();i++){
        cout<<output->at(i)<<",";
    }

    return 0;
}