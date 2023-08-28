/*
Template Class
--------------
allows functions and classes to operate with generic types. This allows a function or class declaration to reference via a generic variable another different class without creating full declaration for each of these different classes

*/

#include <iostream>
using namespace std;

template<class T>

class Rectangle{
    private:
        T l;
        T b;
    
    public:
        Rectangle(T l, T b);
        T area();
        T peri();
};

// :: - Scope Resolution allow to define functions outside the class
template<class T>
Rectangle<T>::Rectangle(T l, T b){
    this->l = l;
    this->b = b;
}

template<class T>
T Rectangle<T>::area(){
    return l * b;
}

template<class T>
T Rectangle<T>::peri(){
    return 2*(l + b);
}


int main()
{
    Rectangle<int> r1(10, 5);
    Rectangle<float> r2(10.9, 5.4);
    
    cout<<"Area: "<<r1.area()<<" Perimeter: "<<r1.peri()<<endl;
    cout<<"Area: "<<r2.area()<<" Perimeter: "<<r2.peri()<<endl;
    return 0;
}
