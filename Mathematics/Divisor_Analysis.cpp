// Problem -> https://cses.fi/problemset/task/2182
// Solution -> https://usaco.guide/problems/cses-2182-divisor-analysis/solution

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
using ll = long long;

ll binpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  ll cnt = 1, sum = 1, prod = 1, cntPow = 1;

  for (int i = 0; i < n; i++) {
    ll x, k;
    cin >> x >> k;

    cnt = cnt * (k + 1) % mod;

    sum = sum * (binpow(x, k + 1) - 1) % mod * binpow(x - 1, mod - 2) % mod;

    prod = binpow(prod, k + 1) * binpow(binpow(x, k * (k + 1) / 2), cntPow) % mod;
    cntPow = cntPow * (k + 1) % (mod - 1);
  }

  cout << cnt << " " << sum << " " << prod << endl;
}