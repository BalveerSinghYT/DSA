#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->next = NULL;
    }
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};


void create(int arr[], int n, Node* &head){
    Node *t, *last;
    
 
    // last will help us to insert new node
    last = head;                    // (last == head) where as head -> next = head 

    for (int i=1; i<n; i++){
        Node* t = new  Node();
        t->data = arr[i];
        t->next = last->next;       // mean pointing to head;
        last->next = t;
        last = t;
    }
}

void display(Node* h){
    Node* head = h;
    do{
        cout<<h->data<<" ";
        h = h->next;
    }while(head != h);
    cout<<"\n";
}

int main(){
    int A[] = {1, 2, 3, 4, 5};

    // creating first circular linklist with one node
    Node* head = new Node(A[0]);
    head->next = head;

    // cout<<head->data;

    create(A, 5, head);
    display(head);
    return 0;
}