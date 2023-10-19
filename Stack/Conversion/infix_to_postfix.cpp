// To convert an infix expressiont to postfix using stack

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int isOperand(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 0;
    else
        return 1;
}

int order(char ch){
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

int main(){
    string infix = "a+b*c-d/e";
    string postfix;
    stack<int> st;
    int i=0, j=0;

    while (infix[i] != '\0'){
        if (isOperand(infix[i]) == 1){
            postfix.push_back(infix[i++]);
        }
        
        else{
            if (st.empty() == false)
                if (order(infix[i]) > order((char)st.top()))
                    st.push(infix[i++]);
                
                else{
                    postfix.push_back((char)st.top());
                    st.pop();
                }
            else
                st.push(infix[i++]);
        }
    }

    while (st.empty() == false){
        postfix.push_back((char)st.top());
        st.pop();
    }
    
    cout<<postfix<<endl;

    return 1;
}