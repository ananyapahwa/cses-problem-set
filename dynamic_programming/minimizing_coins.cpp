#include<bits/stdc++.h>
using namespace std;
// int solve(vector<int>& coins, int currSum, int x){
//     if(currSum == x) return 0;
//     if(currSum > x) return INT_MAX;
    
//     int ans = INT_MAX;
    
//     for(int i=0; i<coins.size(); i++){
//         int take = solve(coins, currSum+coins[i], x);
//         if(take != INT_MAX)
//             ans = min(ans, 1+take);
        
//     }
    
//     return ans;
// }
int main(){
    int n, x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    vector<long long> dp(x+1, INT_MAX);
    dp[x] = 0;
    for(int i=x-1; i>= 0; i--){
        int ans = INT_MAX;
        for(int j=0; j<coins.size(); j++){
            if(i+coins[j] <= x){
                int take = dp[i+ coins[j]];
                if(take != INT_MAX)
                    ans = min(ans, 1 + take);
            }
        }
        
        dp[i] = ans;
    }
    if(dp[0] == INT_MAX) cout<<-1<<endl;
    else cout<<dp[0];

}
