#include<iostream>
using namespace std;

class Array{
    public:
    int arr[10];
    int length;
    int size;

    void display(){
        for (int i=0; i<length; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }

    int get(int index){
        if (index>=0 && index<=length)
            return arr[index];
        return -1;
    }

    void set(int index, int x){
        if (index >= 0 && index<=length)
            arr[index] = x;
        else
            cout<<"Set failed! Index out of range..."<<endl;
    }

    int max(){
        int maxi = 0;
        for (int i=0; i<length; i++){
            if (arr[i]>maxi)
                maxi = arr[i];
        }
        return maxi;
    }

    int min(){
        int mini = arr[0];
        for (int i=1; i<length; i++){
            if (arr[i]<mini)
                mini = arr[i];
        }
        return mini;
    }

    int sum(){
        int sum = 0;
        for (int i=0; i<length; i++)
            sum += arr[i];
        return sum;
    }

    void swap(int &xindex, int &yindex){
        int temp = xindex;
        xindex = yindex;
        yindex = temp;
    }

    void isSorted(){
        for (int i=0; i<length-1; i++){
            if (arr[i] > arr[i+1]){
                cout<<"Not sorted in ascending"<<endl;
                return;
            }
        }
        cout<<"Sorted in ascending"<<endl;
    }
};


int main(){
    Array a1 = {{1, 2, 3, 4, 5, 6, 7, 8}, 8, 10};

    // a1.display();
    // cout<<a1.get(4);
    // a1.set(4, 44);
    // a1.display();
    // cout<<"Max in array: "<<a1.max()<<endl;
    // cout<<"Min in array: "<<a1.min()<<endl;
    // cout<<"Sum of array: "<<a1.sum()<<endl;
    a1.swap(a1.arr[2], a1.arr[3]);
    a1.isSorted();
    a1.display();
    return 0;
}