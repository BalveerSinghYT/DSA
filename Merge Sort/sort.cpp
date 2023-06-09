#include<iostream>

using namespace std;

struct Stack
{
    int size;
    int top;
    int* arr;
};


int main(void){
    struct Stack S;
    S.size = 80;
    S.top = -13;
    S.arr = new int;



    return 0;
}
