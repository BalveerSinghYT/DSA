#include <iostream>
using namespace std;

class Node{
    public:
    
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

// print out the linked list
void printList(Node* &head){
    Node* temp = head;

    while (temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

// Length of Linked List
int length(Node* &head){
    Node* temp = head;
    int cnt = 0;

    while (temp != NULL){
        cnt++;
        temp = temp -> next;
    }
    return cnt;
}

void insertAtBeg(Node* &head, int d){
    Node* temp = head;

    Node* newNode = new Node(d);

    temp -> prev = newNode;
    newNode -> next = temp;
    head = newNode;
}

void insertAtEnd(Node* &tail, int data){
    Node* newNode = new Node(data);

    tail -> next  = newNode;
    newNode -> prev = tail;
    tail = tail -> next;
}

void insertAtPosition(Node* &head, int data, int position){
    Node* temp = head;
    Node* newNode = new Node(data);
    int cnt = 1;

    if (position == 1){
        insertAtBeg(head, data);
        return;
    }

    while (temp != NULL){
        if (cnt == position-1){
            newNode -> prev = temp;
            newNode -> next = temp -> next;
            temp -> next = newNode;
            temp = newNode;
            return;
        }

        cnt++;
        temp = temp -> next;
    }
    cout<<"Position is invalid, Given position is > Length of List";

}

// void deleteNode(Node* &head, int data){
//     Node* temp = head;

//     while (temp != NULL){
//         if (temp -> data == data){
//             temp -> next = 
//         }

//         temp = temp -> next;
//     }
// }

int main(){

    Node* list = new Node(10);
    Node* head = list;
    Node* tail = list;
    printList(head);
    cout<<"Length of Linked List: "<<length(list)<<endl;

    // insertAtBeg(head, 5);
    insertAtBeg(head, 3);
    printList(head);

    insertAtEnd(tail, 15);
    insertAtEnd(tail, 20);
    printList(head);

    insertAtPosition(head, 5, 5);   // position starting from 1
    printList(head);

    cout<<"Head: "<<head -> data<<" Tail: "<<tail -> data<<endl;


}