#include<iostream>
using namespace std;

int length(string s){
    int cnt = 0 ;
    for (int i=0; s[i]!='\0'; i++)
        cnt++;
    return cnt;
}

string upper(string s){
    for (int i=0; s[i]!= '\0'; i++)
        if ((int)s[i] >= 97 && (int)s[i]<=122)
            s[i] = s[i] - 32;
    return s;
}

string lower(string s){
    for (int i=0; s[i]!= '\0'; i++)
        if ((int)s[i] >= 65 && (int)s[i]<=90)
            s[i] = s[i] + 32;
    return s;
}

int count_words(string s){
    int cnt = 0;
    for (int i=0; s[i] != '\0'; i++){
        if (s[i] == ' ' && s[i-1] != ' ')
            cnt++;
        if (s[i] == ' ' && s[i+1] == '\0')
            return cnt;
    }
    return cnt+1;
}

int count_vowels(string s){
    int cnt = 0; 
    s = lower(s);

    for (int i=0; s[i] != '\0'; i++)
        if ((int)s[i] == 97 || (int)s[i] == 101 || (int)s[i] == 105 || (int)s[i] == 111 || (int)s[i] == 117)
            cnt++;
    return cnt;
}

void reverse(string &s){
    for (int i=0, j=length(s)-1; i<j; i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

bool is_palindrome(string s){
    string temp = lower(s);

    for (int i=0, j=length(s)-1; i<j; i++, j--)
        if (temp[i] != temp[j]){
            cout<<"False"<<endl;
            return false;
        }
    cout<<"True"<<endl;
    return true;
}

int main(){
    string s = "Hello World! Welcome  to the  world of Programming...";
    // cout<<length(s);
    // cout<<upper(s);
    // cout<<lower(s);
    // cout<<count_words(s);
    // cout<<count_vowels("aei$$#ou");
    // reverse(s);
    cout<<is_palindrome("NiTin");
}