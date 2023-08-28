#include <iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    
    public:
    
    // default constructor
    Rectangle(){
        length = 0;
        breadth = 0;
    }
    
    // Parameterized constructor
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
    
    int rarea(){
        return length * breadth;
    }
    
    int rperi(){
        return 2*(length + breadth);
    }
    
    // Destructor - auto called at the end
    ~Rectangle(){
        cout<<"Destructor"<<endl;
    }
};

int main()
{
    // Rectangle r;
    int l, b;
    
    cout<<"Enter length & breadth: ";
    cin>>l>>b;
    
    Rectangle r(l,b);
    
    int area = r.rarea();
    int peri = r.rperi();
    
    cout<<"Area: "<<area<<" Perimeter: "<<peri<<endl;
    return 0;
}