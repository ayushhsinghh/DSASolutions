#include<iostream>
#include "Node.cpp"
using namespace std;



/* 
Boundary Conditions:

1. Check for i=0;
2. creater counter = 0 and use While loop to got the one elment before insertation index;
3. check for temp != NULL


*/


Node* insertNode(Node *head , int i , int data) {
    
    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
    }
    else{
        Node *newNode = new Node(data);
        if(i == 0){   
            newNode -> next = head;
            head = newNode;
            return head;   
        }
        else{
        int count =0;
        Node *temp = head;
        while(temp != NULL && count < i-1){
            temp = temp ->next;
            count++;
        }
        
        if(temp != NULL){
        Node *a = temp ->next;
        temp -> next = newNode;
        newNode ->next = a;
        }
        }
        
    }
    return head;

}





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
    int i , data;
    Node *head = takeInput();

    cin>>i>>data;
    head = insertNode(head , i , data);
    print(head);

    
    return 0;
}