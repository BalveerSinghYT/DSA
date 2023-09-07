#include<iostream>
using namespace std;

class Array{
    private:
        int* A;
        int size;
        int length;

    public:

    Array (int size, int length, bool sorted=false){
        this->size = size;
        this->length = length;

        A = new int[size];

        if (sorted){
            cout << "Enter ints in sorted manner" << endl;
            for (int i = 0; i < length; i++){
                cout << "Enter element " << i << " : " << flush;
                cin >> A[i];
            }
        } else {
            for (int i = 0; i < length; i++){
 
                int val;
                val = rand() % 100;  // Random int in range 0 to 100
 
                // Generate random binary int and make value negative
                if (rand() % 2){
                    A[i] = -1 * val;
                } else {
                    A[i] = val;
                }
            }
        }
    }

    void display(){
        for (int i = 0; i < length; i++)
            cout << A[i] << " ";
        cout << endl;
    }

    void set(int index, int x){
        if (index>=0 && index<=length){
            A[index] = x;
        }
    }

    Array merge(Array &B){  // return type is Array

        // creating a new array of size A + B
        Array C(length + B.length, length + B.length);

        int i=0;
        int j=0;
        int k=0;

        while (i<length && j<B.length){
            if (A[i]<B.A[j])
                C.set(k++, A[i++]);

            else
                C.set(k++, B.A[j++]);
        }

        for (;i<length; i++){
            C.set(k++, A[i]);
        }

        for (;j<length; j++){
            C.set(k++, B.A[j]);
        }

        return C;
    }

    ~Array (){
        delete[] A;
    }
};


int main(){
    Array a1(10, 5, true);
    Array a2(10, 4, true);

    a1.merge(a2).display();
    return 0;
}