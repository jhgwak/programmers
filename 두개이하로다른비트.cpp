#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long long bitcnt(int v){
    v = (v & 0x55555555) + ((v >> 1) & 0x55555555);
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
    v = (v & 0x0f0f0f0f) + ((v >> 4) & 0x0f0f0f0f);
    v = (v & 0x00ff00ff) + ((v >> 8) & 0x00ff00ff);
    v = (v & 0x0000ffff) + ((v >> 16) & 0x0000ffff);
    return v;
}
int main(){
    vector<long long>numbers={2,7};
    vector<long long>answer;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]%2==0){
            answer.push_back(numbers[i]+1);
        }
        else if(numbers[i]==1){
            answer.push_back(2);
        }
        else{
            long long bit=1;
            while(1){
                if((numbers[i]&bit)==0)break;
                bit=bit*2;
            }
            bit=bit/2;
            answer.push_back(numbers[i]+bit);
        }
    }

}