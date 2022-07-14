#include <string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>>numbers(rows, vector<int>(columns));
    int count=1;
    int x;
    int y;
    int val1=0;
    int val2=0;
    vector<int>cage;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            numbers[i][j]=count;
            count++;
        }
    }
    for(int i=0;i<queries.size();i++){
        x=queries[i][0]-1;
        y=queries[i][1]-1;
        for(int j=y;j<=queries[i][3]-1;j++){
            cage.push_back(numbers[x][j]);
            val2=j;
        }
        y=val2;
        for(int k=x+1;k<=queries[i][2]-1;k++){
            cage.push_back(numbers[k][y]);
            val1=k;
        }
        x=val1;
        for(int w=y-1;w>=queries[i][1]-1;w--){
            cage.push_back(numbers[x][w]);
            val2=w;
        }
        y=val2;
        for(int z=x-1;z>queries[i][0]-1;z--){
            cage.push_back(numbers[z][y]);
            val1=z;
        }
        x=val1-1;


        int size=(queries[i][2]-queries[i][0])*2+2*(queries[i][3]-queries[i][1]);
        int aa=cage[size-1];
        cage.push_back(aa);
        for(int i=size;i>=0;i--){
            cage[i]=cage[i-1];
        }
        cage[0]=aa;
        cage.erase(cage.end()-1);

        x=queries[i][0]-1;
        y=queries[i][1]-1;
        int increase=0;
        for(int j=y;j<=queries[i][3]-1;j++){
            numbers[x][j]=cage[increase];
            increase++;
            val2=j;
        }
        y=val2;
        for(int k=x+1;k<=queries[i][2]-1;k++){
            numbers[k][y]=cage[increase];
            increase++;
            val1=k;
        }
        x=val1;
        for(int w=y-1;w>=queries[i][1]-1;w--){
            numbers[x][w]=cage[increase];
            increase++;
            val2=w;
        }
        y=val2;
        for(int z=x-1;z>queries[i][0]-1;z--){
            numbers[z][y]=cage[increase];
            increase++;
            val1=z;
        }

        int min=*min_element(cage.begin(),cage.end());
        answer.push_back(min);
        cage.clear();
    }

    return answer;
}