// Problem -> https://cses.fi/problemset/task/2185
// Solution -> https://usaco.guide/problems/cses-2185-prime-multiples/solution

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(k);
  for (ll &it : a) cin >> it;

  ll ans = 0;

  for (ll i = 1; i < (1 << k); i++) {
    ll prod = 1;

    for (ll j = 0; j < k; j++) {
      if (i & (1 << j)) {
        if (prod > n / a[j]) {
          prod = n + 1;
          break;
        }

        prod *= a[j];
      }
    }

    if (__builtin_popcount(i) & 1) ans += n / prod;
    else ans -= n / prod;
  }

  cout << ans << endl;
}