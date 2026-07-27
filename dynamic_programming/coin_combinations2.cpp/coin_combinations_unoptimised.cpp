#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
// int solve(vector<int>& coins, int x, int curr){
//     if(curr == x) return 1;
//     if(curr > x) return 0;
    
//     int ans = 0;
//     for(int i=0; i<coins.size(); i++){
//         ans += solve(coins, x, curr+coins[i]);
//     }
    
//     return ans;
// }
int main() {
	int n, x;
	cin>>n>>x;
	vector<int>coins(n);
	for(int i=0; i<n;i++) cina>>coins[i];
	
	vector<int> dp(x+1, 0);
	dp[x] = 1;
	for(int curr = x-1; curr >= 0; curr--){
	    int ans = 0;
	    for(int i=0; i<coins.size(); i++){
	        if(curr + coins[i] <= x)
                 ans = (ans + dp[curr+coins[i]])%MOD;
            }
            
            dp[curr] = ans;
	  }
	cout<<dp[0];

}
