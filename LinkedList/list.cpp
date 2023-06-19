#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

// Insertion at front
void insertAtHead(Node* &head, int d){  
    
    // new node create
    Node* temp = new Node(d);
    temp -> next = head;        // head is already pointing to previous node & we are storing that address to temp->next
    head = temp;                // chaning the head pointer from previous to temp
}

// Insertion at end
void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

// Insert at position
void insertAtPosition(int position, Node* &head, int d){
    if (position == 1){
        insertAtHead(head, d);
        return;
    }
    Node* pointer = head;
    int count = 1;

    while(count != position-1){
        pointer = pointer -> next;
        count++;
    }

    Node* newNode = new Node(d);
    Node* temp = pointer->next;
    pointer -> next = newNode;
    pointer = newNode;
    pointer ->next = temp;
}

// deletion using linear search
void deleteNode(Node* &head, int x){
    Node* temp = head;
    while (temp != NULL){
        if (temp -> data == x){
            Node* nex = temp -> next;
            temp -> data = nex -> data;
            temp -> next = nex ->next;
            nex = nex -> next;
        }
        temp = temp -> next;
    }
}

// deletion using position
void deleteNodePosition(Node* &head, int pos){
    int count = 0;
    Node* temp = head;

    while (temp != NULL){
        if (count == pos){
            deleteNode(head, temp->data);
        }
        count++;
        temp = temp -> next;
    }
}

// Printing the linked list
void printLinkedList(Node* &head){
    Node* temp = head;
    while (temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"Null \n";
}

int main(){
    // Initial Linked List
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 20);
    // printLinkedList(head);
    insertAtHead(head, 50);

    insertAtTail(tail, 5);
    insertAtTail(tail, 1);
    insertAtHead(head, 100);

    insertAtPosition(1, head, 75);
    printLinkedList(head);

    deleteNode(head, 10);
    cout<<"After deletion of Node 10: "<<endl;
    printLinkedList(head);

    deleteNodePosition(head, 3);
    cout<<"After deletion of Node 3: "<<endl;
    printLinkedList(head);

}