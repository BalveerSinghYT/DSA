#include <iostream>
#include <vector>

using namespace std;

int main(){
    //----------------- Size & Capacity ---------------------
    vector<int> v;

    // initial memory capacity of vector is zero
    cout<<"Initial Capacity-> "<<v.capacity()<<endl;

    // size is the no. of elements in vector
    cout<<"Initial Size-> "<<v.size()<<endl;

    // push a single number to vector
    v.push_back(1);  // 1       1
                    // size, capacity
    v.push_back(2); //  2       2
    v.push_back(3); //  3       4
    v.push_back(4); //  4       4
    v.push_back(5); //  5       8

    cout<<"Final Capacity-> "<<v.capacity()<<endl;
    cout<<"Final Size-> "<<v.size()<<endl;

    /*
    Note:
        Did you notice?
            The Final Capacity after adding three elements is 4, but the size is 3.
        Reason:
            The reason is that whenever a new element is pushed to the vector, it creates a new vector of dobule size of the old one and copies the data to it. Once data is copied it delete the old vector.

        It meas that the capacity of vector is always in 2^n. i.e: 1, 2, 4, 8, 16, 32...
    */

    cout<<"\nVector elements: ";
    for (auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    // ---------------- Indexing -----------------
    cout<<"At index 3: "<<v.at(3)<<endl;
    cout<<"Front: "<<v.front()<<endl;
    cout<<"Back: "<<v.back()<<endl;

    //--------------- Removing & clearing Vector ----------
    // removing last element
    v.pop_back();

    cout<<"\nVector elements: ";
    for (auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    // Clear will remove all the elements, i.e size = 0, capacity = NoChange
    // v.clear();
    // cout<<"Size after clear is "<<v.size()<<", Capacity after clear: "<<v.capacity()<<endl;
    
    //---------------------- Iterator & Initializer --------------------
    
    // Declaring iterator to a vector
    vector<int>::iterator ptr;
    cout<<"Printing using Iterator: ";
    for (ptr = v.begin(); ptr<v.end(); ptr++){
        cout<<*ptr<<" ";
    }

    // Creating a vector of size 10, having ones
    vector<int> ones(10, 1);
    cout<<"\nOnes Vector: ";
    for(auto i:ones){
        cout<<i<<" ";
    }

    return 0;
}
