// Problem -> https://cses.fi/problemset/task/1715

#include<bits/stdc++.h>
using namespace std;

int inverse(int x, int mod) {
  return x <= 1 ? x : mod - 1ll * mod / x * inverse(mod % x, mod) % mod;
}

int main() {
  int maxN = 1e6 + 1, mod = 1e9 + 7;
  vector<int> fact(maxN, 1);

  for (int i = 2; i < maxN; i++)  fact[i] = 1ll * fact[i - 1] * i % mod;

  string s;
  cin >> s;

  vector<int> cnt(26);
  for (char &it : s) cnt[it - 'a']++;

  int ans = fact[s.size()];
  for (int &it : cnt) ans = 1ll * ans * inverse(fact[it], mod) % mod;

  cout << ans << endl;
}