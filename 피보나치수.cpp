#include <string>
#include <vector>

using namespace std;
vector<long>dp(100000);
int fibo(int n){
    int mod=1234567;
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    return dp[n];
}
int solution(int n) {
    int answer = 0;
    answer=fibo(n);
    return answer;
}