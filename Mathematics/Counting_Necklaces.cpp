// Problem -> https://cses.fi/problemset/task/2209

/*
burnside lemma is used for rotation and reflection questions
like given n nodes and m colors find the total number of distinct ways to color all nodes and rotating and reflecting that shape gives the same way
  1. find the axis of rotation and reflection
  2. for each rotation and reflection find the minimum number of nodes to color such that the whole shape is colored in that rotation or reflection without overlap
  3. ways = (sum of m^cnt[i]) / total number of rotations and reflections, because there are cnt[i] number of nodes which have m choices of colors and others are colored with the same color in that rotation or reflection

here there are n rotations and cnt[i]=gcd(i,n) where 0 <= i < n
ways = (sum of m^gcd(i,n)) / n
*/

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int binpow(int x, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    n >>= 1;
  }
  return res;
}

int inverse(int x) {
  return x <= 1 ? x : mod - 1ll * mod / x * inverse(mod % x) % mod;
}

int main() {
  int n, m;
  cin >> n >> m;

  int sum = 0;
  for (int i = 0; i < n; i++) sum = (sum + binpow(m, __gcd(i, n))) % mod;

  cout << 1ll * sum * inverse(n) % mod << endl;
}