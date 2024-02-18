// Problem -> https://cses.fi/problemset/task/1666

#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis) {
  vis[i] = 1;

  for (auto &it : adj[i]) {
    if (!vis[it]) dfs(it, adj, vis);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> ans;
  vector<bool> vis(n + 1);

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ans.push_back(i);

      dfs(i, adj, vis);
    }
  }

  cout << ans.size() - 1 << endl;
  for (int i = 1; i < ans.size(); i++) cout << ans[i - 1] << " " << ans[i] << endl;
}