#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#include<String>
using namespace std;


class TrieNode{
    public:
    char data;
    TrieNode **children;
    bool isEnd;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie{
    TrieNode *root;

    void insert(TrieNode *root , string word){
        // Base Case
        if(word.size() == 0){
            root->isEnd = true;
            return;
        }

        // Logic
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insert(child , word.substr(1));
    }

    bool search(TrieNode *root , string word){
        if(word.size() == 0){
            if(root->isEnd == true){
                return true;
            }
            else{
                return false;
            }
        }
        
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            return search(root->children[index] , word.substr(1));
        }else
        {
            return false;
        }
            
    }

        // not a perfect print Function
    void print(TrieNode *root){

        
        if(root == NULL){
            return;
        }
        for(int i = 0; i < 26 ; i++){
            if(root->children[i] != NULL){
                cout<<root->children[i]->data;
                if(root->children[i]->isEnd == true){
                    cout<<endl;
                }
                if(root->children[i]->children != NULL){
                    
                    print(root->children[i]);
                }
                else{
                    break;
                }

            }
        }
        
    }


    public:
    // Constructor
    Trie(){
        this->root = new TrieNode('\0');
    }

    
    // insert for user
    void insert(string word){
        return insert(root , word);
    }

    bool search(string word){
        return search(root , word);
    }





    

    void print(){
        return print(root);
    }



};


int main(){

    Trie t;
    t.insert("hello");
    t.insert("world");
    t.insert("king");
    t.insert("kingdom");

    // t.print();

    bool check = t.search("king");

    cout<<check; //if check is 1 means True

    


return 0;
}