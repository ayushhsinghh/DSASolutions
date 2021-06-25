#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Tree Node Class
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;


    TreeNode(T data){
        this->data = data;
    }

};

// Print Tree (Not Level-Wise)
void printTree(TreeNode<int> *root){
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0 ;i <  root->children.size() ; i++){
        printTree(root->children[i]);
    }
}

// print Tree Level Wise
void printTreeByLevel(TreeNode<int> *root){
    queue<TreeNode<int>*> nodes;
    nodes.push(root);
    while(nodes.size() != 0){
        TreeNode<int>* front = nodes.front();
        cout<<front->data<<":";
        nodes.pop();
        for(int i=0 ;i < front->children.size() ;i++){
            cout<<front->children[i]->data<<",";
            nodes.push(front->children[i]);
        }
        cout<<endl;
    }

}

// Input in Tree : Not level Wise
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int numChild;
    cout<<"Enter Number of Children of"<<rootData<<endl;
    cin>>numChild;
    for(int i=0;i<numChild;i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}


// Taking Input LevelWise
TreeNode<int>* TakeInputByLevel(){
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNode;

    pendingNode.push(root);

    while(pendingNode.size() != 0){
        TreeNode<int>* front = pendingNode.front();
        pendingNode.pop();
        cout<<"Enter Number of Children of" << front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild; i++){
            int childData;
            cout<<"Enter "<<i<<"th term of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> * child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }

    }

    return root;
}




int main(){

    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);
    TreeNode<int> *node3 = new TreeNode<int>(4);
    TreeNode<int> *node4 = new TreeNode<int>(5);

    root->children.push_back(node1);
    root->children.push_back(node2);
    node1->children.push_back(node3);
    node1->children.push_back(node4);


    
    // TreeNode<int> *root = takeInput();
    // TreeNode<int> *root = TakeInputByLevel();
    // printTree(root);
    printTreeByLevel(root);


    return 0;
}