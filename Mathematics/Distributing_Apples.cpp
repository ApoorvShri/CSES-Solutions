// Problem -> https://cses.fi/problemset/task/1716

/*
x1 + x2 + ..... + xn = m, such that 0 <= xi <= m
no. of solution = (m+n-1)C(n-1) or (m+n-1)C(m)
*/

#include<bits/stdc++.h>
using namespace std;

int inverse(int x, int mod) {
  return x <= 1 ? x : mod - 1ll * mod / x * inverse(mod % x, mod) % mod;
}

int main() {
  int maxN = 2e6, mod = 1e9 + 7;
  vector<int> fact(maxN, 1);

  for (int i = 2; i < maxN; i++)  fact[i] = 1ll * fact[i - 1] * i % mod;

  int n, m;
  cin >> n >> m;

  cout << 1ll * fact[n + m - 1] * inverse(fact[m], mod) % mod * inverse(fact[n - 1], mod) % mod << endl;
}