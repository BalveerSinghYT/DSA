#include<iostream>
using namespace std;

class Queue{
    private:
        int arr[10];
        int front;
        int rear;
        int size;

    public:

    Queue(int n){
        this->front = -1;
        this->rear = -1;
        this->size = n;
    }

    void enqueue(int x);
    void dequeue();
    void display();
};

void Queue::enqueue(int x){
    if (rear != size-1)
        if (rear < size-1){
            arr[rear++] = x;
        }
    else
        cout<<"Overflow..."<<endl;
}

void Queue::dequeue(){
    if (front == rear)
        cout<<"Queue is empty";
    else
        front++;
}

void Queue::display(){

    for (int i=front; i<rear; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    Queue* qList = new Queue(5);
    
    qList->enqueue(1);
    qList->enqueue(2);
    qList->enqueue(3);
    qList->enqueue(4);
    qList->dequeue();
    qList->dequeue();
    qList->enqueue(4);
    qList->dequeue();
    qList->display();
    return 0;
}