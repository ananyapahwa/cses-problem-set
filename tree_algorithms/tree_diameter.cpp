#include <bits/stdc++.h>
using namespace std;
int diameter = 0;
int dfs(vector<vector<int>> &adj, int currNode, int parent) {
  // we reached the leaf node
  int largest = 0;
  int secondLargest = 0;
  // if(adj[currNode].size() == 1 && adj[currNode][0] == parent)  return 1;

  for (int n : adj[currNode]) {
    if (n == parent)
      continue;

    int depth = 1 + dfs(adj, n, currNode);
    if (depth > largest) {
      secondLargest = largest;
      largest = depth;
    } else if (depth > secondLargest) {
      secondLargest = depth;
    }
  }

  diameter = max(diameter, largest + secondLargest);
  return largest;
}
int main() {
  // your code goes here

  int n;
  cin >> n;
  int a, b;
  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int temp = dfs(adj, 1, -1);

  cout << diameter << endl;

  return 0;
}
