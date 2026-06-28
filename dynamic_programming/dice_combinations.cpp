#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

// int solve(int n, int currSum) {
//     if(currSum == n) return 1;
//     if(currSum > n) return 0;
//     int ans = 0;
//     for(int i=1; i<=6; i++){
//         ans += solve(n, currSum+i);
//     }
//     return ans;
// }
int main(){
    int n;
    cin>>n;
    vector<long long>dp(n+1, 0);
    dp[n] = 1;
    for(int i=n-1; i>=0; i--){
        int ans = 0;
        for(int j=1; j<=6; j++){
            if(i+j <= n)
                ans = (ans + dp[i+j]) % MOD;
        }
      dp[i] = ans;
    }
    cout<<dp[0]<<endl;
}

