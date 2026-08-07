#include <bits/stdc++.h>
using namespace std;

vector<int> findDigits(int n) {
  vector<int> digits;
  while (n != 0) {
    digits.push_back(n % 10);
    n /= 10;
  }

  return digits;
}
// int solve( int n){
//     if(n==0) return 0;
//     int ans = INT_MAX;
//     vector<int> digits = findDigits(n);

//     return ans;
// }
int main() {
  // your code goes here
  int n;
  cin >> n;
  int ans = 0;
  vector<int> dp(n + 1, 0);
  for (int num = 1; num <= n; num++) {
    ans = INT_MAX;
    vector<int> digits = findDigits(num);
    for (int i = 0; i < digits.size(); i++) {
      if (digits[i] != 0 && num >= digits[i])
        ans = min(ans, 1 + dp[num - digits[i]]);
    }

    dp[num] = ans;
  }

  cout << dp[n] << endl;

  return 0;
}
