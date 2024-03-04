// Problem -> https://cses.fi/problemset/task/1668

#include<bits/stdc++.h>
using namespace std;

bool cycle(int &node, int cur, vector<int> &team, vector<vector<int>> &adj) {
  team[node] = cur;

  for (auto &child : adj[node]) {
    if (team[child] == 0) {
      if (cycle(child, cur ^ 3, team, adj)) return 1;
    }

    else if (team[child] == cur) return 1;
  }

  return 0;
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> team(n + 1);

  for (int i = 1; i <= n; i++) {
    if (team[i] == 0 && cycle(i, 1, team, adj)) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  for (int i = 1; i <= n; i++) cout << team[i] << " ";
  cout << endl;
}