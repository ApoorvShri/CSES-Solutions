// Problem -> https://cses.fi/problemset/task/1079

#include<bits/stdc++.h>
using namespace std;

int inverse(int x, int mod) {
  return x <= 1 ? x : mod - 1ll * mod / x * inverse(mod % x, mod) % mod;
}

int main() {
  int maxN = 1e6 + 1, mod = 1e9 + 7;
  vector<int> fact(maxN, 1);

  for (int i = 2; i < maxN; i++)  fact[i] = 1ll * fact[i - 1] * i % mod;

  int t;
  cin >> t;

  while (t--) {
    int n, r;
    cin >> n >> r;

    cout << 1ll * fact[n] * inverse(fact[r], mod) % mod * inverse(fact[n - r], mod) % mod << endl;
  }
}