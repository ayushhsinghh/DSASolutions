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

// arr : Sorted Array
// low : First index
// high : last index
BinaryTreeNode<int>* arrayToBST(int arr[] , int low , int high){
    if(low < high){
        int mid;
        mid = (low+high)/2;
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
        root->left = arrayToBST(arr , low , mid);
        root->right = arrayToBST(arr , mid+1 , high);
        return root;
    }
    return NULL;
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

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    BinaryTreeNode<int> *root = arrayToBST(arr , 0 , 9);

    printTreeByLevel(root);




    return 0;
}



