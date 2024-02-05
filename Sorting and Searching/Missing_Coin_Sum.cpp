// Problem -> https://cses.fi/problemset/task/2183

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  sort(a.begin(), a.end());
  long long ans = 1;

  for (auto &it : a) {
    if (it > ans) break;
    ans += it;
  }

  cout << ans << endl;
}