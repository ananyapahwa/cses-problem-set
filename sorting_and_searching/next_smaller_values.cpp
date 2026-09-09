#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++)
    cin >> x[i];

  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {

    while (!st.empty() && x[st.top()] > x[i]) {
      ans[st.top()] = i + 1;
      st.pop();
    }

    st.push(i);
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";

  return 0;
}
