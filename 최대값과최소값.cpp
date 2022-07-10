#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    string s="1 2 3 4";
    vector<int>b;
    string answer="";
    string a="";
    int check=0;
    int value=0;
    s=s+' ';
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            if (check==1){
                value= stoi(a);
                value=value*-1;
                b.push_back(value);
                check=0;
            }
            else{
                value= stoi(a);
                b.push_back(value);
            }
            a="";
        }
        else if(s[i]=='-'){
            check=1;
        }
        else{
            a=a+s[i];
        }
    }
    sort(b.begin(),b.end());

    answer=to_string(b[0]);
    answer=answer+' ';
    answer=answer+to_string(b[b.size()-1]);

    cout<<answer;

}