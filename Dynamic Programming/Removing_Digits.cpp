// Problem -> https://cses.fi/problemset/task/1637

#include<bits/stdc++.h>
using namespace std;

// Recursion
/*
int fn(int n) {
  if (n == 0) return 0;

  int num = n, ans = INT_MAX;

  while (n) {
    int dig = n % 10;
    n /= 10;

    if (dig) ans = min(ans, 1 + fn(num - dig));
  }

  return ans;
}
*/

// Memoization
/*
int fn(int n, vector<int> &dp) {
  if (n == 0) return 0;
  if (dp[n] != -1) return dp[n];

  int num = n, ans = INT_MAX;

  while (n) {
    int dig = n % 10;
    n /= 10;

    if (dig) ans = min(ans, 1 + fn(num - dig, dp));
  }

  return dp[n] = ans;
}
*/

int main() {
  int n;
  cin >> n;

// Recursion
/*
  cout << fn(n) << endl;
*/

// Memoization
/*
  vector<int> dp(n + 1, -1);
  cout << fn(n, dp) << endl;
*/

// Tabulation
  vector<int> dp(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int num = i, ans = INT_MAX;

    while (num) {
      int dig = num % 10;
      num /= 10;

      if (dig) ans = min(ans, 1 + dp[i - dig]);
    }

    dp[i] = ans;
  }

  cout << dp[n] << endl;
}