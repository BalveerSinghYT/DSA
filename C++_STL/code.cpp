
#include <bits/stdc++.h>
using namespace std;

int main() {

    
    // Pairs in C++ STL
    pair<int, string> p;
    p = {2, "abcd"};
    cout<<"Orignal P: "<<p.first <<" "<< p.second << endl;
    
    // copying ( creates an independent duplicate copy)
    pair<int, string> p1 = p;
    p1.first = 4;
    cout<<"\nCopy of P, P1: "<<p1.first <<" "<< p1.second << endl;
    cout<<"didn't changed orignal P: "<<p.first <<" "<< p.second << endl;
    
    // referencing (creates a dependent copy, changes in one will reflect in other)
    pair<int, string> &p2 = p;
    p2.first = 4;
    cout<<"\nReference of P, P2: "<<p2.first <<" "<< p2.second << endl;
    cout<<"changed orignal P: "<<p.first <<" "<< p.second << endl;

    

    // Pairing two arrays
    int a[] = {1, 2, 3};
    int b[] = {2, 4, 6};

    pair<int, int> q[3];
    q[0] = {a[0], b[0]};
    q[1] = {a[1], b[1]};
    q[2] = {a[2], b[2]};

    cout<<"Before: \n";
    for (int i=0; i<3; i++){
        cout<<q[i].first<<" "<<q[i].second<<endl;
    }
    // swapping 1st row with 3rd row
    swap(q[0], q[2]);
    
    cout<<"\n After: \n";
    for (int i=0; i<3; i++){
        cout<<q[i].first<<" "<<q[i].second<<endl;
    }
}