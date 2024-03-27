// Problem - https://cses.fi/problemset/task/1652

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<string> a(n);
  for (auto &it : a) cin >> it;

  vector<vector<int>> pf(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + (a[i - 1][j - 1] == '*');
  }

  while (q--) {
    int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
    cout << pf[i2][j2] - pf[i2][j1 - 1] - pf[i1 - 1][j2] + pf[i1 - 1][j1 - 1] << endl;
  }
}