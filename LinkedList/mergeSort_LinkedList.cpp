#include<iostream>
#include<vector>
#include "Node.cpp"
using namespace std;

// Merge Function Recursive
// Node* mergeR(Node* first , Node* second){
//     Node *result = NULL;

//     if(first == NULL){
//         return second;
//     }
//     else if(second == NULL){
//         return first;
//     }
//         if(first->data <= second ->data){
//             result = first;
//             result ->next = merge(first -> next , second);
//         }
//         else{
//             result = second;
//             result -> next  = merge(first , second -> next);
//         }


//     return result;
// }

Node* merge(Node* first , Node* second)
{
    Node *p1 = first;
    Node *p2 = second;
    Node *newNode = new Node(-1);
    Node *p3 = newNode;

    while(p1 !=NULL && p2 !=NULL){
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3 ->next; 
    }

    while(p1 != NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3 ->next;
    }
    while(p2 != NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3 ->next;
    }

    return newNode->next;
}


void splitLL(Node *source , Node** first , Node** second){
    Node *slow = source;
    Node *fast = source -> next;

    while(fast != NULL){   
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow -> next;
        }
    }
    *first = source;
    *second = slow -> next;
    slow->next =NULL;

}



void mergesort(Node**  head){
    Node *cur = *head;
    Node *first;
    Node *second;

    if(cur == NULL || cur->next == NULL){
        return;
    }
    else{
        splitLL(cur , &first , &second);
        mergesort(&first);
        mergesort(&second);
        *head = merge(first , second);
        // *head = mergeR(first , second);   //Recursive method

    }



}







Node* takeInput(){
    int data;
    cin>>data;
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

int lengthLL(Node *head){
    int count = 0;
    if(head == NULL){
        cout<<"List is Empty"<<endl;
    }
    else{
        
        Node *temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
    }

    return count;
    

}

void print(Node *head){
    if(head == NULL){
        cout<<"List is Empty"<<endl;
    }
    else{
        while(head != NULL){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
    }
}


int main(){

    Node *head = takeInput();
    cout<<"Given Linked List : ";
    print(head);
    cout<<"Sorted Linked List : ";
    mergesort(&head);
    print(head);

    return 0;
}