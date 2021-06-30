#include <iostream>
#include<queue>

using namespace std;

template<typename T>
class AVLNode{
    public:
        T data;
        AVLNode<T>* left;
        AVLNode<T>* right;

        AVLNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};


class AVL{
    private:
    AVLNode<int> *root;
    int height(AVLNode<int>* root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(height(root->left) , height(root->right));
    }

    int treeBalance(AVLNode<int>* root){
        if(root == NULL){
            return 0;
        }
        return height(root->left) - height(root->right);;
    }

    // node : the root element
    // This is Not LL Rotation
    AVLNode<int>* leftRotation(AVLNode<int>* node){

        // 2 temp Node:
        AVLNode<int>* rootRightTemp = node->right;
        AVLNode<int>* rootRightsLeftTemp = rootRightTemp->left;

        // Left Rotation
        rootRightTemp->left = node;
        node->right = rootRightsLeftTemp;

        return rootRightTemp; //new Root
    }



    // node : the root element
    // This is Not LL Rotation
    AVLNode<int>* rightRotation(AVLNode<int>* node){
        // 2 temp Nodes:
        AVLNode<int>* rootLeftTemp = node->left;
        AVLNode<int>* rootLeftsRightTemp = rootLeftTemp->right;

        // Right Rotation:
        rootLeftTemp->right = node;
        node->left = rootLeftsRightTemp;


        return rootLeftTemp; //new Root
    }

    AVLNode<int>* insert(int num , AVLNode<int>* node){
        if(node == NULL){
            AVLNode<int> *root = new AVLNode<int>(num);
            return root;
            }
        if(node->data > num){
            node->left =  insert(num , node->left);
        }
        else if(node->data < num){
            node->right =  insert(num , node->right);
        }
        else{
            return node;
        }
        int balance = treeBalance(node);

        // Left-Left Rotation (LL)
        // if balance > 1 (left-skewed)
        // the element added is less then the root's left element
        if(balance  > 1 && num < node->left->data){
            return rightRotation(node);
        }


        // Right-Right Rotation (RR)
        // if Balanace < -1 (right-skewed)
        // the element added is greater then root's right element
        if(balance < -1 && num > node->right->data){
            return leftRotation(node);
        }

        // Left-Right Rotation (LR)
        // if Balanace > 1 (left skewed)
        // the element added is greater then root's left elements
        if (balance > 1 && num > node->left->data){
            node->left = leftRotation(node->left);
            return rightRotation(node);

        }

        // Right-Left Rotation (RL)
        // if balance < -1 (Right Skewed)
        // the element added is smalled then the root's right element
        if(balance < -1 && num < node->right->data){
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }


        return node;
    }
    AVLNode<int>* remove(int num , AVLNode<int>* node){
        if(node == NULL){
            return NULL;
        }
        if(num < node->data){
            node->left = remove(num , node->left);
            return node;
        }
        else if(num > node->data){
            node->right = remove(num , node->right);
            return node;
        }
        else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->left == NULL){
                AVLNode<int>* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                AVLNode<int>* temp = node->left;
                delete node;
                return temp;
            }
            else{
                AVLNode<int>* minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int minNodeValue = minNode->data;
                node->data = minNodeValue;
                node->right = remove(minNodeValue , node->right);
                return node;
            }
        }

        int balance = treeBalance(node);

        // Left-Left Rotation (LL)
        // if balance > 1 {Left Skewed}
        // when the root's left tree  balance >= 0
        if(balance >1 & treeBalance(node->left) >= 0){
            return rightRotation(node);
        }


        // Right-Right Rotation (RR)
        // if balance < -1 {right Skewed}
        // when the root's right tree  balance <= 0
        if(balance  < -1 & treeBalance(node->right) <= 0){
            return leftRotation(node);
        }

        // Left-Right Rotation (LR)
        // if balance > 1 {Left Skewed}
        // roots'left balance is < 0
        if(balance > 1 & treeBalance(node->left) < 0){
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }

        // Right-Left Rotation { RL }
        // if balance < -1 {Right Skewed}
        // root's right tree balance is > 0

        if(balance < -1 & treeBalance(node->right) > 0){
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }  


        return node;
    }


    public:
    AVL(){
        this->root = NULL;
    }

    AVLNode<int>* insert(int data){
        this->root = insert(data, this->root);
        return root;
    }

    AVLNode<int>* remove(int data){
        this->root = remove(data, this->root);
        return root;
    }



    // Level Order traversal
    void print(){
    queue<AVLNode<int>*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        AVLNode<int> *front = nodes.front();
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
};
int main(){

    AVL q;

    // insert Operation Check
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);
    q.insert(50);
    q.insert(35);
    q.insert(6);
    q.insert(46);
    q.insert(26);
    
    q.print();

    // delete check4

    cout<<"New Tree is : "<<endl;
    q.remove(10);
    q.remove(20);
    q.remove(30);

    q.print();

    
    return 0;
}