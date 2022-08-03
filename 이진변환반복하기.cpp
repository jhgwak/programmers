#include<iostream>
#include<string>
#include<vector>

using namespace std;
int number1=0;
string rmzeor(string s){
    string ns;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            number1++;
        }
        else{
            ns=ns+s[i];
        }
    }
    return ns;
}
string mkbinary(string s){
    int num=stoi(s);
    string ns="";
    while(num!=1){
        ns=ns+ to_string(num%2);
        num=num/2;
    }
    ns=ns+"1";
    std::reverse(ns.begin(), ns.end());
    return ns;

}
int main(){
    string s="110010101001";
    vector<int>answer;
    int number2=0;
    while(s!="1"){
        string ns= rmzeor(s);
        if(ns.size()==s.size()){
            ns=mkbinary(to_string(ns.size()));
            number2++;
        }
        s=ns;
    }
    answer.push_back(number1);
    answer.push_back(number2+1);

}