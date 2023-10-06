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

void create(int arr[], int n, Node *&head)
{
    Node *t, *last;

    // last will help us to insert new node
    last = head; // (last == head) where as head -> next = head

    for (int i = 1; i < n; i++)
    {
        Node *t = new Node();
        t->data = arr[i];
        t->next = last->next; // mean pointing to head;
        last->next = t;
        last = t;
    }
}

void display(Node *h)
{
    Node *head = h;
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while (head != h);
    cout << "\n";
}

void insert_at_pos(Node *&h, int pos, int x)
{
    if (pos == 0)
    {
        if (h == NULL)
        {
            Node *temp = new Node(x);
            h->next = temp;
            temp->next = h;
        }
        else
        {
            Node *temp = new Node(x);
            temp->next = h;
            Node *loop = h;
            while (loop->next != h)
                loop = loop->next;
            loop->next = temp;
            h = temp;
        }
    }
    else
    {
        int i = 0;
        Node *head = h;

        while (i < pos - 1)
        {
            head = head->next;
            i++;
        }
        Node *temp = new Node(x);
        temp->next = head->next;
        head->next = temp;
    }
}

void deletion(Node *&head, int pos)
{
    if (head == NULL)
    {
        // List is empty
        return;
    }

    Node *temp = head;

    // Traverse the list to find the node to delete
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if (temp == head && temp->next == head)
    {
        // Only one node in the list
        head = NULL;
    }
    else if (temp == head)
    {
        // Deleting the first node
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
    }
    else
    {
        // Deleting a node other than the first node
        Node *p = temp->next;
        temp->next = p->next;
        delete p;
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};

    // creating first circular linklist with one node
    Node *head = new Node(A[0]);
    head->next = head;

    // cout<<head->data;

    create(A, 5, head);
    display(head);

    insert_at_pos(head, 5, 55);
    display(head);

    deletion(head, 1);
    display(head);
    return 0;
}