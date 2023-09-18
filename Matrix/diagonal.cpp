#include<iostream>
using namespace std;

class Diagonal{
    private:
        int *A;
        int n;
    public:

    Diagonal(){
        n = 2;
        A = new int[n];
    }

    Diagonal(int n){
        this->n = n;
        A = new int[n];
    }

    ~Diagonal(){
        delete []A;
    }

    // i, j are position & x is the vale
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagonal::Set(int i, int j, int x){
    if (i == j)
        A[i-1] = x;     // in real world considering starting index 1, but in program we r having 0
}

int Diagonal::Get(int i, int j){
    if (i == j)
        return A[i-1];
    return 0;
}

void Diagonal::Display(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i == j)
                cout<<A[i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){
    Diagonal A(3);

    A.Set(0,0, 1);
    A.Set(1,1, 2);
    A.Set(2,2, 3);

    A.Display();
    return 0;
}
