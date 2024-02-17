// Problem -> https://cses.fi/problemset/task/1095

#include<bits/stdc++.h>
using namespace std;

int binpow(int x, int n) {
  int res = 1, mod = 1e9 + 7;

  while (n) {
    if (n & 1) res = (1ll * res * x) % mod;
    x = (1ll * x * x) % mod;
    n >>= 1;
  }

  return res;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, b;
    cin >> a >> b;

    cout << binpow(a, b) << endl;
  }
}