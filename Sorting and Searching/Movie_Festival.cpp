#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> a(n);
  for (auto &[en, st] : a) cin >> st >> en;

  sort(a.begin(), a.end());

  int ans = 0, prev = 0;
  for (auto &[en, st] : a) {
    if (st >= prev) {
      ans++;
      prev = en;
    }
  }

  cout << ans << endl;
}