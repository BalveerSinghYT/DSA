#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    map<string, int> scoreCard;

    scoreCard["veer"] = 92;
    scoreCard["jackie"] = 83;
    scoreCard["ron"] = 44;

    map<string, int>::iterator iter;

    for(iter = scoreCard.begin(); iter != scoreCard.end(); iter++){
        cout<<(*iter).first<<" "<<(*iter).second<<endl;

        
    }

    return 0;
}