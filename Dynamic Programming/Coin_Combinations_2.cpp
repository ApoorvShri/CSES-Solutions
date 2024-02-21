// Problem -> https://cses.fi/problemset/task/1636

#include<bits/stdc++.h>
using namespace std;

// Recursion
/*
int fn(int i, int sum, int &n, vector<int> &a, int &mod) {
  if (sum == 0) return 1;
  if (i == n) return 0;

  if (sum - a[i] >= 0) return (fn(i, sum - a[i], n, a, mod) + fn(i + 1, sum, n, a, mod)) % mod;
  return fn(i + 1, sum, n, a, mod);
}
*/

// Memoization
/*
int fn(int i, int sum, int &n, vector<int> &a, int &mod, vector<vector<int>> &dp) {
  if (sum == 0) return 1;
  if (i == n) return 0;

  if (dp[i][sum] != -1) return dp[i][sum];

  if (sum - a[i] >= 0) return dp[i][sum] = (fn(i, sum - a[i], n, a, mod, dp) + fn(i + 1, sum, n, a, mod, dp)) % mod;
  return dp[i][sum] = fn(i + 1, sum, n, a, mod, dp);
}
*/

int main() {
  int n, x, mod = 1e9 + 7;
  cin >> n >> x;

  vector<int> a(n);
  for (int &it : a) cin >> it;

  // Recursion
/*
  cout << fn(0, x, n, a, mod) << endl;
*/

  // Memoization
/*
  vector<vector<int>> dp(n, vector<int>(x + 1, -1));
  cout << fn(0, x, n, a, mod, dp) << endl;
*/

  // Tabulation
/*
  vector<vector<int>> dp(n + 1, vector<int>(x + 1));
  for (int i = 0; i <= n; i++) dp[i][0] = 1;

  for (int i = n - 1; i >= 0; i--) {
    for (int sum = 1; sum <= x; sum++) {
      if (sum - a[i] >= 0) dp[i][sum] = (dp[i][sum - a[i]] + dp[i + 1][sum]) % mod;
      else dp[i][sum] = dp[i + 1][sum];
    }
  }

  cout << dp[0][x] << endl;
*/

  // Space optimized
  vector<int> prev(x + 1), cur(x + 1);
  for (int i = 0; i <= n; i++) prev[0] = cur[0] = 1;

  for (int i = n - 1; i >= 0; i--) {
    for (int sum = 1; sum <= x; sum++) {
      if (sum - a[i] >= 0) cur[sum] = (cur[sum - a[i]] + prev[sum]) % mod;
      else cur[sum] = prev[sum];
    }

    prev = cur;
  }

  cout << prev[x] << endl;
}