#include<iostream>
#include "Node.cpp"
using namespace std;




// Less Time Complexity
pair<Node* , Node*> reverse(Node* head){
    if(head == NULL || head->next== NULL){
        pair<Node* , Node*> p;
        p.first = head;
        p.second = head;
        return p;
    }

    pair<Node* , Node*> last = reverse(head->next);

    last.second->next = head;
    head->next = NULL;

    pair<Node* , Node*> ans;
    ans.first = last.first;
    ans.second = head;
    return ans;
    };


// Recursice Way : More Time complexity

// Node* reverseLL(Node* head){
//     if(head == NULL || head->next == NULL){
//         return head;
//     }

//     Node* last = reverseLL(head->next);

//     Node* temp = last;
//     while(temp->next != NULL){
//         temp = temp->next;
//     }

//     temp->next = head;
//     head->next = NULL;
//     return last;
// }



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
    if(head == NULL){
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
    pair<Node* , Node*> pq = reverse(head);
    cout<<"After Reverses "<<endl;
    print(pq.first);


    return 0;
}