#include<algorithm>
#include<string>
#include<vector>

using namespace std;
vector<string> split(string a){
    vector<string>vec1;
    vector<string>res;
    int count=0;
    for(int i=0;i<a.size();i++){
        vec1.push_back(a.substr(i,2));
        for(int j=0;j<2;j++){
            if(vec1[i][j]>='a'&&vec1[i][j]<='z'){
                count++;
            }
            else if(vec1[i][j]>='A'&&vec1[i][j]<='Z'){
                vec1[i][j]=vec1[i][j]+32;
                count++;
            }
            else{
                count=0;
                break;
            }
            if(count==2){
                res.push_back(vec1[i]);
                count=0;
            }
        }
    }
    return res;
}
bool check[1000]={0,};
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> vec1;
    vector<string> vec2;
    int size=0;
    float res=0.0;

    vec1=split(str1);
    vec2=split(str2);
    if(vec1.size()==0&&vec2.size()==0){
        answer=65536;
        return answer;
    }
    else{
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        for(int i=0;i<vec1.size();i++){
            for(int j=0;j<vec2.size();j++){
                if(vec1[i]==vec2[j]){
                    if(check[j]!=1){
                        size++;
                        check[j]=1;
                        break;
                    }

                }
            }
        }
        int a=vec1.size();
        int b=vec2.size();
        res=float(size)/float(a+b-size);
        answer=res*65536;
        return answer;
    }
}