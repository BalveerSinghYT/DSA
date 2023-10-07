#include <iostream>
using namespace std;

class Node{
    public:
    
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->next = NULL;
        this->prev = NULL;
    }

    // Constructor
    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

// create doubly-ll
Node* create(Node* first, int arr[], int length){
    Node* last = first;

    for (int i=1; i<length; i++){
        Node* newNode = new Node(arr[i]);
        newNode->prev = last;
        first->next = newNode;
        first = newNode;
        last = last->next;
    }
    return last;
}

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

int deleteNode(Node* &head, int pos){
    Node* temp = head;
    int x = -1;

    if (pos < 1 || pos >length(temp))
        return -1;
    
    if (pos == 1){
        x = temp->data;
        head = temp->next;
        if (head)
            head->prev = NULL;
        
        delete temp;
    }
    else{
        for (int i=0; i<pos-1; i++)
            temp = temp->next;
        
        temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        x = temp->data;
        delete temp;
    }
    return x;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* head = new Node(arr[0]);
    Node* tail;
    tail = create(head, arr, n);
    printList(head);

    insertAtEnd(tail, 6);
    printList(head);

    int x = deleteNode(head, 1);
    if (x != -1)
        cout<<x<<" is deleted"<<endl;
    printList(head);
}