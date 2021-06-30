#include<iostream>
#include "Node.cpp"
using namespace std;


Node* reverseLL(Node* head){


    return head;
}



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