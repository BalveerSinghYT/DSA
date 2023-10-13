#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    private:
    Node* top;
    int size;
    int cnt;

    public:
    Stack(int size){
        this->cnt = 0;
        this->size =  size;
        this->top = NULL;
    }

    void display();
    void push(int x);
    void pop();
    void peek();
};

void Stack::display(){
    while (top != NULL){
        cout<<top->data<<" ";
        top = top->next;
    }
}

void Stack::push(int x){
    if (cnt < size){
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        cnt++;
        cout<<x<<" is inserted in stack"<<endl;
    }
    else
        cout<<"\nStack Overflow!!\n";
}

void Stack::pop(){
    if (top != NULL){
        int x = top->data;
        top = top->next;
        cnt--;
        cout<<"\n"<<x<<" is removed from stack..."<<endl;
    }
    else
        cout<<"\nStack Underflow\n";
}

void Stack::peek(){
    int data;

    if (top == NULL)
        cout<<"\nStack is Empty!"<<endl;
    else{
        data = top->data;
        cout<<"\nTop element in stack is "<<data<<endl;
    }
    
}

int main(){
    Stack* st = new Stack(5);

    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    st->push(6);
    st->pop();
    st->peek();
    st->pop();
    st->push(6);

    st->display();


    return 0;
}