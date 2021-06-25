#include <iostream>
#include <queue>
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

};

/*
                1
               / \
              2  3
             /\ /\
            4 5 6 7


 */ 

void leftView(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        BinaryTreeNode<int> *cur;
        int levelNodes = nodes.size();
        for(int i = 0 ; i<levelNodes ; i++){
            cur = nodes.front();
            nodes.pop();

            if(i == 0)
            {
                cout<<cur->data<<" ";
            }
            if(cur->left){
                nodes.push(cur->left);
            }if(cur->right){
                nodes.push(cur->right);
            }
        }
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
    cout<<"Left View : ";
    leftView(root);

    return 0;

}