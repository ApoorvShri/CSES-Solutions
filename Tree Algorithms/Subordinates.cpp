// Problem -> https://cses.fi/problemset/task/1674

#include<bits/stdc++.h>
using namespace std;

int dfs(int i, vector<vector<int>> &adj, vector<int> &ans) {
  for (auto &it : adj[i]) ans[i] += dfs(it, adj, ans);
  return 1 + ans[i];
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);

  for (int i = 2;i <= n;i++) {
    int x;
    cin >> x;

    adj[x].push_back(i);
  }

  vector<int> ans(n + 1);
  dfs(1, adj, ans);

  for (int i = 1;i <= n;i++) cout << ans[i] << " ";
  cout << endl;
}