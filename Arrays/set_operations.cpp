#include<iostream>
using namespace std;

class Array{
    private:
    int *A;
    int length;

    public:
        
    Array(int length){
        this->length = length;

        A = new int[length];
    }

    void set(int arr[], int l){
        for (int i=0; i<l; i++){
            A[i] = arr[i];
        }
        // if (index>=0 && index<=length)
        //     A[index] = x;
    }

    void display(){
        for (int i=0; i<length; i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }

    // ----- Union of two arrays -------
    Array unions(Array &B){
        Array C(length + B.length);

        int i=0, j=0, k=0;

         while(i<length && j<B.length){
            if(A[i]<B.A[j])
                C.A[k++] = A[i++];

            else if(B.A[j] < A[i])
                C.A[k++] = B.A[j++];
            else
            {
                C.A[k++] = A[i++];
                j++;
            }
        }

        for(; i<length; i++)
            C.A[k++] = A[i];
        for(; j<B.length; j++)
            C.A[k++] = B.A[j];

        C.length=k;

        return C;
    }
    // void intersection();
    // void difference();

};

int main(){
    Array A(4);
    Array B(5);
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 2, 7, 4, 8};

    A.set(arr1, 4);
    B.set(arr2, 5);

    Array Z(10);
    Z = A.unions(B);
    cout<<"After Merge: ";
    Z.display();
    
    return 1;
}