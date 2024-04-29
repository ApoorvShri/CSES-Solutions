// Problem -> https://cses.fi/problemset/task/1717

/*
Derangement(n) - no. of ways to arrange n people into n houses such that no one goes into their house (house[i]!=i)
d(n) = (n-1) * (d(n-1) + d(n-2))
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  int prev1 = 1, prev2 = 0, mod = 1e9 + 7;

  for (int i = 3, cur; i <= n; i++) {
    cur = 1ll * (i - 1) * (prev1 + prev2 % mod) % mod;
    prev2 = prev1;
    prev1 = cur;
  }

  cout << prev1 << endl;
}