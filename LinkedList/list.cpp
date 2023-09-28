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

// Length of LinkedList
int countLength(Node* &head){
    if (head == NULL)
        return 0;
    else
        return countLength(head->next) + 1;
}

// Min of LinkedList
int min(Node* head){
    int x = head->data;

    while (head != NULL){
        if (head->data < x){
            x = head->data;
        }
        head = head->next;
    }
    return x;
}

// Max of LL via Recurssion
int max(Node* head){
    int x = 0;

    if (head == NULL)
        return INT32_MIN;
    
    x = max(head->next);

    if (x > head->data)
        return x;
    else
        return head->data;
}

// Searching
Node* search(Node* head, int x){
    while (head != NULL){
        if (head->data == x)
            return head;
        head = head->next;
    }
    return NULL;
}

Node* recursiveSearch(Node* head, int x){
    if (head == NULL)
        return NULL;

    if (head->data == x)
        return head;
        
    return recursiveSearch(head->next, x);
}

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

// Reverse LL using three pointers
Node* reverse(Node* head){
    Node* p = head;
    Node* q = NULL;
    Node* r = NULL;

    while (p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
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

    cout<<"Length of LinkedList: "<<countLength(head)<<endl;
    cout<<"Min of LinkedList: "<<min(head)<<endl;
    cout<<"Max of LinkedList: "<<max(head)<<endl;
    // deleteNode(head, 10);
    // cout<<"After deletion of Node 10: "<<endl;
    // printLinkedList(head);

    // deleteNodePosition(head, 3);
    // cout<<"After deletion of Node 3: "<<endl;
    printLinkedList(head);
    head = reverse(head);
    printLinkedList(head);

}