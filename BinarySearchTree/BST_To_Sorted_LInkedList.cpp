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

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};



pair<Node* , Node*> bstToLinkedList(BinaryTreeNode<int> * root){
    if(root==NULL){
        pair<Node* , Node*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    };

    pair<Node*,Node*> leftside = bstToLinkedList(root->left);
    pair<Node*,Node*> rightside = bstToLinkedList(root->right);
    

    Node* temp = new Node(root->data);

    if(leftside.first == NULL && leftside.second == NULL){
        pair<Node* , Node*> temp1 = make_pair(temp , temp);
        return temp1;
    }
    else{
        leftside.second->next = temp;
        temp->next = rightside.first;
    }

    pair<Node* , Node*> temp3;
    temp3.first = leftside.first;
    temp3.second = rightside.second;


    return temp3;
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

// Linked List traversal
void printLL(Node *head){
    if(head->data == NULL){
        cout<<"Linked List is empty"<<endl;
    }
    else{
        while(head != NULL){
            cout<<head->data <<endl;
            head = head->next;
        }
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

    cout<<"Linked List is : "<<endl;
    pair<Node* , Node*> temp = bstToLinkedList(root);


    printLL(temp.first);

    return 0;
}



