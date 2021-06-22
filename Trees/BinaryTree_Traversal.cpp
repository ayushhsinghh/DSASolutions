#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// Binary Tree Class
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


// Level Order Print
// Root : left , right
// left : Lchild , Rchild
// right : Lchild , Rchild
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


// Pre-Order Traversal
// First Root then Children
// (Root , Left , Right)
void printPreOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Post-Order Traversal
// First Children then Root
// (Left , Right , Root)
void printPostOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

// In-Order Traversal
// (Left , Root , Right)

void printInOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}



int main(){

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int> *node3 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int> *node4 = new BinaryTreeNode<int>(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;


    // printTreeByLevel(root);
    // printPreOrder(root);
    // printPostOrder(root);
    printInOrder(root);


    return 0;
}