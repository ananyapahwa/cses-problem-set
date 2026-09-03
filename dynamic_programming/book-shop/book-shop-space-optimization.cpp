#include <bits/stdc++.h>
using namespace std;

// int solve(int n, int x, vector<int> &h, vector<int> &s, int idx) {
//   if (idx >= n)
//     return 0;
//   if (x <= 0)
//     return 0;

//   int take = 0;
//   if (h[idx] <= x)
//     take = s[idx] + solve(n, x - h[idx], h, s, idx + 1);
//   int notTake = solve(n, x, h, s, idx + 1);

//   return max(take, notTake);
// }
int main() {

  // taking the input
  int n, x;
  cin >> n >> x;
  vector<int> h(n);
  vector<int> s(n);

  for (int i = 0; i < n; i++)
    cin >> h[i];
  for (int i = 0; i < n; i++)
    cin >> s[i];

  // int ans = solve(n, x, h, s, 0);

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  vector<int> prev(x + 1, 0);
  vector<int> curr(x + 1, 0);
  for (int idx = n - 1; idx >= 0; idx--) {
    for (int price = 0; price <= x; price++) {
      int take = 0;
      if (h[idx] <= price)
        take = s[idx] + prev[price - h[idx]];
      int notTake = prev[price];

      curr[price] = max(take, notTake);
    }

    prev = curr;
  }

  cout << curr[x] << endl;

  return 0;
}
