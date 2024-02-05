#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  sort(a.begin(), a.end());
  int median = (n & 1) ? a[n / 2] : (a[n / 2] + a[n / 2 - 1]) / 2;

  long long ans = 0;
  for (auto &it : a) ans += abs(median - it);

  cout << ans << endl;
}