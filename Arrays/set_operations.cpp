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

    // get element via linear search
    int get(int x){
        for (int i=0; i<length; i++)
            if (A[i] == x)
                return i;
        return -1;
    }

    void display(){
        for (int i=0; i<length; i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }

    // ----- Union of two sorted arrays -------
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

        C.length = k;

        return C;
    }

    Array intersection(Array &B){
        Array C(length+B.length);

        int j=0, k=0;
        for(int i=0; i<length; i++){
            if (B.get(A[i]) != -1){
                C.A[j++] = A[i];
                // k++;
            }
        }
        C.length = j;
        return C;
    }
    Array difference(Array &B){
        int i=0, j=0;
        Array C(length + B.length);

        for (int i=0; i<length; i++){
            if (B.get(A[i]) == -1){
                C.A[j++] = A[i];
            }
        }
        C.length = j;
        return C;
    }
};

int main(){
    Array A(4);
    Array B(5);
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {2, 3, 5, 7, 8};

    A.set(arr1, 4);
    B.set(arr2, 5);

    cout<<"A: ";
    A.display();
    cout<<"B: ";
    B.display();

    Array Z(10);
    Z = A.unions(B);
    cout<<"After Merge: ";
    Z.display();

    // cout<<Z.get(3);
    cout<<"\nIntersection: ";
    A.intersection(B).display();

    cout<<"\nDifference: ";
    A.difference(B).display();
    
    return 1;
}