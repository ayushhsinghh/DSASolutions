#include<iostream>
#include "Node.cpp"
using namespace std;


/* 
Boundary Conditions:


1. Check for head == null
2. use tail for new Node entry


*/

// Take Input Till Data is -1;
Node* takeInput(){
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
        tail -> next = newNode;
        tail = newNode;
        }

        cin>>data;
    }
    return head;
}

// Function to print Linked list
void print(Node *head){
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


int main()
{
    Node *head = takeInput();

    print(head);


    return 0;
}