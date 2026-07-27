// KIND OF 0/1 KNAPSACK

// Space-optimized Bottom-Up DP
// State: dp[curr] = number of ways to reach the target sum x
// starting from the current accumulated sum 'curr' using
// coins from index 'idx' onwards.
// Transition:
//   take    -> use the current coin again (unlimited supply)
//   notTake -> skip the current coin and move to the next.
// We use two 1D arrays (currRow and nextRow) instead of a full
// 2D DP table, reducing the space complexity from O(n*x) to O(x).

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
// int solve(vector<int>& coins, int x, int curr, int idx){
//     if(curr == x) return 1;
//     if(curr > x) return 0;

//     if(idx == coins.size()) return 0;

//     int take = solve(coins, x, curr+coins[idx], idx);
//     int notTake = solve(coins, x, curr, idx+1);

//     return (take + notTake) % MOD;
// }
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];

  vector<int> currRow(x + 1, 0);
  vector<int> nextRow(x + 1, 0);

  nextRow[x] = 1;

  for (int idx = n - 1; idx >= 0; idx--) {
    fill(currRow.begin(), currRow.end(), 0);
    currRow[x] = 1;
    for (int curr = x - 1; curr >= 0; curr--) {
      int take = 0;
      if (curr + coins[idx] <= x)
        take = currRow[curr + coins[idx]];

      int notTake = nextRow[curr];

      currRow[curr] = (take + notTake) % MOD;
    }
    nextRow = currRow;
  }
  cout << nextRow[0];

  return 0;
}
