#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void concate(Node *first, Node *second)
{

    while (first->next != NULL)
    {
        first = first->next;
    }

    first->next = second;
}

Node *merge(Node *first, Node *second)
{
    Node *temp = new Node(0);
    Node *third = temp;
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            third->next = first;
            first = first->next;
        }
        else
        {
            third->next = second;
            second = second->next;
        }
        third = third->next;
    }
    if (first != NULL)
        third->next = first;
    else if (second != NULL)
        third->next = second;
    temp = temp->next;
    return temp;
}

int main()
{
    int arr1[] = {1, 3, 5, 7, 9, 11, 13};
    int arr2[] = {2, 6, 4, 8, 10};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *first = new Node(arr1[0]);
    Node *second = new Node(arr2[0]);

    // Creating LL-1, LL-2
    create(first, arr1, n1);
    create(second, arr2, n2);

    // Printing First, Second
    cout << "First: ";
    print(first);
    cout << "Second: ";
    print(second);

    // concate(first, second);
    // cout<<"Concate: ";
    // print(first);

    Node *third;
    third = merge(first, second);
    // cout<<third->data;
    print(third);

    return 0;
}