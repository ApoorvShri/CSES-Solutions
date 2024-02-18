// Problem -> https://cses.fi/problemset/task/1647

#include<bits/stdc++.h>
using namespace std;

int MAXN = 2e5;
vector<vector<int>> st(log2(MAXN) + 1, vector<int>(MAXN));

// Operation
int op(int &x, int &y) {
  return min(x, y);
}

void build(int n, vector<int> &a) {
  int m = log2(n);

  for (int i = 0; i <= m; i++)
    for (int j = 0; j + (1 << i) <= n; j++) {
      if (i == 0) st[0][j] = a[j];

      else st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
}

// Idempotent -> A op A = A
// Like -> min, max, gcd, &, |
int query1(int l, int r) {
  l--;
  r--;

  int length = r - l + 1;
  int log = log2(length);

  return op(st[log][l], st[log][r - (1 << log) + 1]);
}

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  build(n, a);

  while (q--) {
    int l, r;
    cin >> l >> r;

    cout << query1(l, r) << endl;
  }
}