#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int solve(vector<vector<char>> &grid, int i, int j, int n) {
  if (i == n - 1 && j == n - 1)
    return 1;
  if (i >= n || j >= n)
    return 0;
  if (grid[i][j] == '*')
    return 0;
  // go right
  int r = solve(grid, i, j + 1, n);
  // go down
  int d = solve(grid, i + 1, j, n);

  return (r + d) % MOD;
}

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
  cout << solve(grid, 0, 0, n) << endl;
  x
}
