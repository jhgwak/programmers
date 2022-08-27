#include <string>
#include <vector>
#include<algorithm>
using namespace std;
bool cmp(pair<string,int>a,pair<string,int>b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    else{
        return a.second<b.second;
    }
}
string change(string a){
    for(char&ch :a){
        if('A'<=ch&'Z'>=ch){
            ch|=32;
        }
    }
    return a;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 5;
    vector<pair<string,int>>cache;
    int check=0;
    if(cacheSize==0){
        answer=5*cities.size();
        return answer;
    }
    for(int i=0;i<cities.size();i++){
        cities[i]= change(cities[i]);
    }
    cache.push_back(make_pair(cities[0],1));
    for(int i=1;i<cities.size();i++){
        for(int j=0;j<cache.size();j++){
            if(cities[i]==cache[j].first){
                check=1;
                cache[j].second=1;
                answer=answer+1;
            }
            else{
                cache[j].second++;
            }
        }
        if(check==0){
            if(cache.size()==cacheSize){
                sort(cache.begin(),cache.end(),cmp);
                cache.pop_back();
                cache.push_back(make_pair(cities[i],1));
                answer=answer+5;
            }
            else{
                cache.push_back(make_pair(cities[i],1));
                answer=answer+5;
            }
        }
        else{
            check=0;
        }
    }
    return answer;
}