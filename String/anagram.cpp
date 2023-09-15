#include<iostream>
using namespace std;

string lower(string s){
    for (int i=0; s[i]!= '\0'; i++)
        if ((int)s[i] >= 65 && (int)s[i]<=90)
            s[i] = s[i] + 32;
    return s;
}

int length(string s){
    int cnt = 0 ;
    for (int i=0; s[i]!='\0'; i++)
        cnt++;
    return cnt;
}

bool is_anagram(string a, string b){
    int i=0, H[26] = {0};

    if (length(a) != length(b)){
        cout<<"Length not equal"<<endl;
        return false;
    }

    a = lower(a);
    b = lower(b);

    for (i=0; a[i] != '\0'; i++)
        H[a[i]-97] += 1;
    
    for (i=0; b[i] != '\0'; i++){
        if (H[b[i]-97] < 0){
            cout<<"Not an Anagram..."<<endl;
            return false;
        }
        else
            H[b[i]-97] -= 1;
    }
    cout<<"It's an anagram"<<endl;
    return true;
}


int main(){
    string a = "Veer";
    string b = "Ceer";

    cout<<is_anagram(a, b);
}