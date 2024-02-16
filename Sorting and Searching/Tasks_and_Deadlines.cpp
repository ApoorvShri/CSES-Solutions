// Problem -> https://cses.fi/problemset/task/1630

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> a(n);
  for (auto &it : a) cin >> it.first >> it.second;

  sort(a.begin(), a.end());
  long long sum = 0, ans = 0;

  for (auto &it : a) {
    sum += it.first;
    ans += it.second - sum;
  }

  cout << ans << endl;
}