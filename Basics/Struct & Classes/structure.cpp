#include <iostream>

using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

void initialize(Rectangle *r, int l, int b){
    r->length = l;
    r->breadth = b;
}

int rarea(Rectangle r){
    return r.length * r.breadth;
}

int rperi(Rectangle r){
    return 2*(r.length + r.breadth);
}


int main()
{
    Rectangle r = {0,0};
    int l, b;
    
    cout<<"Enter length & breadth: ";
    cin>>l>>b;
    
    initialize(&r, l, b);
    
    int area = rarea(r);
    int peri = rperi(r);
    
    cout<<"Length: "<<r.length<<" Breadth: "<<r.breadth<<endl;
    cout<<"Area: "<<area<<" Perimeter: "<<peri<<endl;

    return 0;
}