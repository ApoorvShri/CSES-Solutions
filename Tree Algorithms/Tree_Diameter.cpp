// Problem -> https://cses.fi/problemset/task/1131

#include<bits/stdc++.h>
using namespace std;

void calculatePaths(int node, int par, vector<vector<int>> &adj, vector<int> &path) {
  int maxChildPath = 0;
  bool isLeaf = 1;

  for (auto &child : adj[node]) {
    if (child != par) {
      isLeaf = 0;
      calculatePaths(child, node, adj, path);
      maxChildPath = max(maxChildPath, path[child]);
    }
  }

  if (isLeaf) path[node] = 0;
  else path[node] = 1 + maxChildPath;
}

void calculateDiameter(int node, int par, vector<vector<int>> &adj, vector<int> &path, vector<int> &diameter) {
  int ans = 0;
  vector<int> childPaths;

  for (auto &child : adj[node]) {
    if (child != par) {
      calculateDiameter(child, node, adj, path, diameter);
      childPaths.push_back(path[child]);
      ans = max(ans, diameter[child]);
    }
  }

  int numOfChilds = childPaths.size();
  sort(childPaths.begin(), childPaths.end());

  if (numOfChilds == 0) diameter[node] = 0;
  else if (numOfChilds == 1) diameter[node] = 1 + childPaths[0];
  else diameter[node] = 2 + childPaths[numOfChilds - 1] + childPaths[numOfChilds - 2];

  diameter[node] = max(diameter[node], ans);
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> path(n + 1), diameter(n + 1);
  calculatePaths(1, 0, adj, path);
  calculateDiameter(1, 0, adj, path, diameter);

  cout << diameter[1] << endl;
}