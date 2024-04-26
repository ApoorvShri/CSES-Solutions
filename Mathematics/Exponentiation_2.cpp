// https://cses.fi/problemset/task/1712

/*
if p is prime
x%(p-1)=1

1. find n=(b^c)%(p-1)
2. find (a^n)%p
*/

#include<bits/stdc++.h>
using namespace std;

int binpow(int x, int n, int mod) {
  int res = 1;
  while (n) {
    if (n & 1) res = (1ll * res * x) % mod;
    x = (1ll * x * x) % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  int t, p = 1e9 + 7;
  cin >> t;

  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    cout << binpow(a, binpow(b, c, p - 1), p) << endl;
  }
}