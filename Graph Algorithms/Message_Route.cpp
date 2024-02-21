// Problem -> https://cses.fi/problemset/task/1667

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  vector<bool> vis(n + 1);
  vector<int> par(n + 1);

  q.push(1);
  vis[1] = 1;
  par[1] = 1;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    if (node == n) {
      vector<int> path;
      while (node != 1) {
        path.push_back(node);
        node = par[node];
      }

      cout << path.size() + 1 << endl << "1 ";
      while (!path.empty()) {
        cout << path.back() << " ";
        path.pop_back();
      }

      cout << endl;
      return 0;
    }

    for (auto &child : adj[node]) {
      if (!vis[child]) {
        q.push(child);
        vis[child] = 1;
        par[child] = node;
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;
}