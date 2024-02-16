// Problem -> https://cses.fi/problemset/task/1620

#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  int n, t;
  cin >> n >> t;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  auto can = [&](int mid) {
    int sum = 0;
    for (auto &it : a) {
      sum += mid / it;
      if (sum >= t) return 1;
    }
    return 0;
    };

  int low = 1, high = 1e18, res;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (can(mid)) {
      res = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  cout << res << endl;
}