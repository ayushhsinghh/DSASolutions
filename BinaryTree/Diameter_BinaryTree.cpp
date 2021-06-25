#include<iostream>
#include<algorithm>
#include<utility>
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

    int height(BinaryTreeNode<int>* root) {
        if(root == NULL) return 0; 
        return 1 + max(height(root->left) , height(root->right)); 
    }

    // Time Complexity is O(n^2) : Not Good
    int diameter(BinaryTreeNode<int>* root){
        if(root == NULL){
            return 0;
        }
        int option1 = height(root->left) + height(root->right);
        int option2 = diameter(root->left); 
        int option3 = diameter(root->right); 
            return max(option1 , max(option2 , option3));        
        }

    // Time Complexity : O(n)
    pair<int , int> diameterOptimized(BinaryTreeNode<int>* root){
        if(root==NULL) {
            pair<int , int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }

        pair<int , int> leftDiameter = diameterOptimized(root->left);
        pair<int , int> rightDiameter = diameterOptimized(root->right);

        int height = 1 + max(leftDiameter.first, rightDiameter.first);
        int diameter = max(leftDiameter.first + rightDiameter.first , max(leftDiameter.second, rightDiameter.second));
        pair<int , int> p;
        p.first = height;
        p.second = diameter;

        return p;
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

    pair<int, int> p = diameterOptimized(root);
    cout<<"Height is :"<<p.first<<endl;
    cout<<"diameter is :"<<p.second<<endl;

    return 0;
}