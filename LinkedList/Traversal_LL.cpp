#include<iostream>
#include "Node.cpp"
using namespace std;



/* 
Boundary Conditions:

1. While Loop till head != NULL
2. keep printing head and increamenting it.


*/

// Traverse Function
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
    Node n1(10);
    Node *head = &n1;

    Node n2(20);
    n1.next = &n2;

    Node n3(30);
    n2.next = &n3;

    Node n4(40);
    n3.next = &n4;

    print(head);
    return 0;
}