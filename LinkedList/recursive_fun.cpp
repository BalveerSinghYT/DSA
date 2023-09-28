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

void print_list(Node* head){
    if (head == NULL){
        cout<<"NULL\n";
        return;
    }
    cout<<head->data<<" -> ";
    return print_list(head->next);
}

void insert_at_end(Node* head, int x){
    if (head->next == NULL){
        Node* newNode = new Node(x);
        head->next = newNode;
        return;
    }
    return insert_at_end(head->next, x);
}

Node* reverse(Node* p, Node* q){
    static Node* head = NULL;

    if (p!=NULL){
        reverse(p->next, p);
        p->next = q;
    }
    else{
        head = q;
    }
    return head;
}

int main(){
    Node* head = new Node(1);
    insert_at_end(head, 2);
    insert_at_end(head, 3);
    insert_at_end(head, 4);
    insert_at_end(head, 5);

    print_list(head);
    Node* temp;
    temp = reverse(head, NULL);
    print_list(temp);

    return 0;
}