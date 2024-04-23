// Problem -> https://cses.fi/problemset/task/1729

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(k);
  for (int &it : a) cin >> it;

  vector<bool> dp(n + 1);

  for (int i = 0; i <= n; i++) {
    if (dp[i] == 0) for (int &it : a) if (it + i <= n) dp[it + i] = 1;

    if (i) cout << (dp[i] ? 'W' : 'L');
  }

  cout << endl;
}