// Problem - https://cses.fi/problemset/task/1662

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  long long ans=0;
  int cur = 0;
  vector<int> cnt(n);
  cnt[0] = 1;

  for (int i = 0, x; i < n; i++) {
    cin >> x;
    cur = ((cur + x) % n + n) % n;
    ans += cnt[cur]++;
  }

  cout << ans << endl;
}