#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int arr[20];
        int top;
    public:
    
    Stack(int size){
        this->size = size;
        this->top = -1;
    }

    void display();
    void push(int data);
    void pop();
};

void Stack::display(){
    for (int i=0; i<=top; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Stack::push(int data){
    if (top<size-1){
        arr[++top] = data;
        cout<<data<<" <-- Inserted"<<endl;
    }
    else
        cout<<"\nStack Overflow!!\n"<<endl;
}

void Stack::pop(){
    if (arr[top] == -1)
        cout<<"Stack is Empty"<<endl;

    else
        cout<<arr[top]<<" <-- is deleted"<<endl;
    top--;
}

int main(){
    //  max stack size is 20

    Stack* st = new Stack(6);
    st->push(5);
    st->push(4);
    st->push(3);
    st->push(2);
    st->push(1);
    st->push(1);
    st->display();
    st->pop();
    st->push(1);
    st->display();
    return 0;
}   