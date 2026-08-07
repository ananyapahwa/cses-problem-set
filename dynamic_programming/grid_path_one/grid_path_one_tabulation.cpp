#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// int solve(vector<vector<char>> &grid, int i, int j, int n){
//     if(i == n-1 && j==n-1) return 1;
//     if(i>=n || j>=n) return 0;
//     if(grid[i][j] == '*') return 0;
//     //go right
//     int r = solve(grid, i, j+1, n);
//     //go down
//     int d = solve(grid, i+1, j, n);

//     return (r+d)%MOD;
// }

int main() {
  // your code goes here
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
    cout << 0 << endl;
    return 0;
  }
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (i == n - 1 && j == n - 1) {
        dp[i][j] = 1;
        continue;
      }
      if (grid[i][j] == '*') {
        dp[i][j] = 0;
        continue;
      }
      int r = 0, d = 0;
      if (j + 1 < n)
        r = dp[i][j + 1];
      if (i + 1 < n)
        d = dp[i + 1][j];

      dp[i][j] = (r + d) % MOD;
    }
  }
  cout << dp[0][0] % MOD << endl;

  return 0;
}
