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

void duplicates(string s){
    int H[26] = {0};

    for(int i=0; s[i]!='\0'; i++)
        H[s[i]-97] += 1;
    
    for (int i=0; i<26; i++)
        if (H[i]>1){
            cout<<"\'"<<char(i+97)<<"\'";
            cout<<"repeated "<<H[i]<<" times"<<endl;
        }

}

void bit_duplicates(string s){
    int x=0, H=0;
    s = lower(s);

    cout<<"Duplicate chars: ";
    for (int i=0; s[i]!='\0'; i++){
        x = 1;

        x = x<<(s[i]-97);

        // & operation will check if x == H using bitwise AND operator
        /*
            Example:
                H = 00010100 i.e. 16 + 4 = 20 (means 16 + 97 = 113('q') and 4 + 97 = 101('e'))
                x = 00000001 i.e 1 (means 1 + 97 = 98('b'))
                x & H = 00000000 i.e. 0 (means 1 + 97 = 98('b') is not present in H)
        */
        if ((x&H)>0)
            cout<<char(s[i])<<" ";

        // here we are making correspoding bit High
        /*
            Example:
                H = 00010100 i.e. 16 + 4 = 20 (means 16 + 97 = 113('q') and 4 + 97 = 101('e'))
                x = 00000001 i.e 1 (means 1 + 97 = 98('b'))
                x | H = 00010101 i.e. 16 + 4 + 1 = 21 (means 16 + 97 = 113('q'), 4 + 97 = 101('e') and 1 + 97 = 98('b'))
        */
        else
            H = x | H;
    }

}


int main(){
    string s = "Hello World! Welcome  to the  world of Programming...";
    // cout<<length(s);
    // cout<<upper(s);
    // cout<<lower(s);
    // cout<<count_words(s);
    // cout<<count_vowels("aei$$#ou");
    // reverse(s);
    // cout<<is_palindrome("NiTin");
    bit_duplicates("HelloWorld");
}