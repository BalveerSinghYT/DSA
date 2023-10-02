#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node()
    {
        this->next = NULL;
    }

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void create(Node *&head, int a[], int n)
{
    Node *temp = head;

    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(a[i]);
        temp->next = newNode;
        temp = temp->next;
    }
}

Node* duplicate(Node* &head){
    Node* curr = head;
    
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data){
            Node* temp = new Node(curr->next);
            curr = curr->next->next;
            delete(temp);
        }
        else
            curr = curr->next;
    }
    return head;
    
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(){
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = new Node(arr[0]);
    
    create(head, arr, n);
    print(head);

    head = duplicate(head);
    print(head);

    return 0;
}