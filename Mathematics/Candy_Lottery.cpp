// Problem -> https://cses.fi/problemset/task/1727

#include<bits/stdc++.h>
using namespace std;

using ld = long double;

ld binpow(ld x, int n) {
  ld res = 1;
  while (n) {
    if (n & 1) res *= x;
    x *= x;
    n >>= 1;
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;

  ld ans = 0;
  for (ld i = 1; i <= k; i++) ans += i * (binpow(i / k, n) - binpow((i - 1) / k, n));

  cout << fixed << setprecision(6) << ans << endl;
}