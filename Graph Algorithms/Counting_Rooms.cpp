// Problem -> https://cses.fi/problemset/task/1192

#include<bits/stdc++.h>
using namespace std;

void dfs(int ii, int jj, int &n, int &m, vector<string> &a, vector<pair<int, int>> &dir) {
  a[ii][jj] = '#';

  for (auto &[x, y] : dir) {
    int i = ii + x, j = jj + y;

    if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.') dfs(i, j, n, m, a, dir);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> a(n);
  for (auto &it : a) cin >> it;

  int ans = 0;
  vector<pair<int, int>> dir{ {-1,0},{0,-1},{0,1},{1,0} };

  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      if (a[i][j] == '.') {
        ans++;
        dfs(i, j, n, m, a, dir);
      }
    }
  }

  cout << ans << endl;
}