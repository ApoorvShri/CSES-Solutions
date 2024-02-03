#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n), b(m);
  for (auto &it : a) cin >> it;
  for (auto &it : b) cin >> it;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int i = 0, j = 0, ans = 0;
  while (i < n && j < m) {
    int mn = a[i] - k, mx = a[i] + k;

    if (b[j] < mn) j++;
    else if (b[j] > mx) i++;
    else ans++, i++, j++;
  }

  cout << ans << endl;
}