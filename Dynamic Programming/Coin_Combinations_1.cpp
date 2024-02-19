// Problem -> https://cses.fi/problemset/task/1635

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, x, mod = 1e9 + 7;
  cin >> n >> x;

  vector<int> a(n);
  for (int &it : a) cin >> it;

  sort(a.begin(), a.end());
  vector<int> dp(x + 1, 0);
  dp[0] = 1;

  for (int sum = 1; sum <= x; sum++) {
    for (int &it : a) {
      if (sum - it >= 0) (dp[sum] += dp[sum - it]) %= mod;
      else break;
    }
  }

  cout << dp[x] << endl;
}