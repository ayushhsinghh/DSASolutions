#include<iostream>
#include "Node.cpp"
using namespace std;

/* 
Boundary Conditions:

1. Check for i=0;
2. creater counter = 0 and use While loop to got the one elment before delete index;
3. check for temp != NULL


*/


Node* deleteNode(Node *head , int i) {
    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
    }
    else{
        int count = 0;
        Node *temp = head;
        if(i==0){
            Node *temp = head;
            head = head->next;
            delete(temp);

            return head;
        }

        while(temp != NULL && count < i-1){
            temp = temp->next;
            count++;
        }
        if(temp != NULL){
            Node *temp2 = temp ->next;
            temp->next = temp2 ->next;
            delete(temp2);
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

    cin>>i;
    head = deleteNode(head , i);
    print(head);

    
    return 0;
}