/*Your loops are:

for (curr = x-1 ... 0)        // x iterations
    for (idx = n-1 ... 0)     // n iterations
        for (i = idx ... n-1) // up to n iterations

So the complexity is

O(x×n×n)=O(xn^2)
With CSES constraints
n≤100
x≤10^6

Worst case:

10^6 × 100 × 100
= 10^10 operations

Ten billion iterations.

That will not finish within the time limit. */



#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int solve(vector<int>& coins, int x, int curr, int idx){
    if(curr == x) return 1;
    if(curr > x) return 0;
    
    int ans = 0;
    for(int i=idx; i<coins.size(); i++){
        ans += solve(coins, x, curr+coins[i], i);
    }
    
    return ans;
}
int main() {
	int n, x;
	cin>>n>>x;
	vector<int>coins(n);
	for(int i=0; i<n;i++) cin>>coins[i];
	
	vector<vector<int>>dp(x+1, vector<int>(n, 0));
	for (int idx = 0; idx < n; idx++)
        dp[x][idx] = 1;
        
        
	for(int curr = x-1; curr >= 0; curr--){
	    for (int idx = n-1; idx >= 0; idx--){
	        int ans = 0;
	    for(int i=idx; i<coins.size(); i++){
	        if(curr + coins[i] <= x)
                 ans = (ans + dp[curr+coins[i]][i])%MOD;
            }
           
            dp[curr][idx] = ans;
	    }
	  }
	cout<<dp[0][0];

// cout<<solve(coins, x, 0, 0);

}
