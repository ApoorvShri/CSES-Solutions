// Problem -> https://cses.fi/problemset/task/1634

#include<bits/stdc++.h>
using namespace std;

int fn(int i, int sum, int &n, vector<int> &a, vector<vector<int>> &dp) {
  if (sum == 0) return 0;
  if (i == n) return 1e9;

  if (dp[i][sum] != -1) return dp[i][sum];

  if (sum - a[i] >= 0) return dp[i][sum] = min(1 + fn(i, sum - a[i], n, a, dp), fn(i + 1, sum, n, a, dp));
  return dp[i][sum] = fn(i + 1, sum, n, a, dp);
}

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  vector<vector<int>> dp(n + 1, vector<int>(x + 1));
  for (int sum = 1; sum <= x; sum++) dp[n][sum] = 1e9;

  for (int i = n - 1; i >= 0; i--) {
    for (int sum = 0; sum <= x; sum++) {
      if (sum - a[i] >= 0) dp[i][sum] = min(1 + dp[i][sum - a[i]], dp[i + 1][sum]);
      else dp[i][sum] = dp[i + 1][sum];
    }
  }

  if (dp[0][x] >= 1e9) cout << -1 << endl;
  else cout << dp[0][x] << endl;
}