#include <iostream>
#include<queue>

using namespace std;

template <typename T>
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


class BST{
    private:
    BinaryTreeNode<int>* root;

    bool hasData(int data , BinaryTreeNode<int>* node){
        if(node == NULL){
            return false;
        }
        if(node->data==data){
            return true;
        }
        else if(root->data > data){
            return hasData(data, node->left);
        }
        else{
            return hasData(data,node->right);
        }
    }
    BinaryTreeNode<int>* insert(int data , BinaryTreeNode<int>* node){
        if(node==NULL){
            BinaryTreeNode<int> * root = new BinaryTreeNode<int>(data);
            return root;
        }
        else if(data > node->data){
            node->right = insert(data , node->right);
            return node;
        }
        else{
            node->left = insert(data , node->left);
            return node;
        }
        return node;
        
    }

    BinaryTreeNode<int>* remove(int data , BinaryTreeNode<int>* node){
        if(node==NULL){
            return NULL;
        }
        if(data > node->data){
            node->right = remove(data , node->right);
            return node;
        }
        else if(data < node->data){
            node->left = remove(data , node->left);
            return node;
        }
        else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->right == NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(node->left == NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int rightMinData = minNode->data;
                node->data = rightMinData;
                node->right = remove(rightMinData , node->right);
                return node;
            }
        }
        
    }


    public:
    BST(){
        root = NULL;
    }

    // Overloding Functions
    bool hasData(int data){
        return hasData(data , root);
    }

    BinaryTreeNode<int>* insert(int data){
        this->root = insert(data , this->root);
        return root;
    }
    BinaryTreeNode<int>* remove(int data){
        this->root = remove(data , this->root);
        return root;
    }

    void print(){
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

    
};



int main(){

    BST q;
    // checking Insert
    q.insert(10);
    q.insert(1);
    q.insert(2);
    q.insert(7);
    q.insert(5);
    q.insert(19);
    q.insert(11);
    q.insert(23);
    q.insert(12);

    q.print();

    // checking search
    bool x = q.hasData(10);
    bool y = q.hasData(6);

    cout<<"data is : "<<x<<","<<y<<endl;

    // checking Delete
    cout<<"New Tree is : "<<endl;
    q.remove(10);
    q.remove(100); // Not Present in Tree : Nothing changes

    q.print();

    
    return 0;
}