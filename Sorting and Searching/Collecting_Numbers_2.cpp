// Problem -> https://cses.fi/problemset/task/2217

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  unordered_map<int, int> ind;
  int ans = 1;

  for (int i = 0;i < n;i++) {
    if (ind.count(a[i] + 1)) ans++;
    ind[a[i]] = i;
  }

  ind[0] = -1;
  ind[n + 1] = n;

  while (m--) {
    int i1, i2;
    cin >> i1 >> i2;

    i1--;
    i2--;

    int num1 = a[i1], num2 = a[i2];
    swap(a[i1], a[i2]);

    if (ind[num1 - 1] <= ind[num1] && ind[num1 - 1] > i2) ans++;
    if (ind[num1 - 1] > ind[num1] && ind[num1 - 1] <= i2) ans--;
    if (ind[num1] <= ind[num1 + 1] && i2 > ind[num1 + 1]) ans++;
    if (ind[num1] > ind[num1 + 1] && i2 <= ind[num1 + 1]) ans--;

    ind[num1] = i2;

    if (ind[num2 - 1] <= ind[num2] && ind[num2 - 1] > i1) ans++;
    if (ind[num2 - 1] > ind[num2] && ind[num2 - 1] <= i1) ans--;
    if (ind[num2] <= ind[num2 + 1] && i1 > ind[num2 + 1]) ans++;
    if (ind[num2] > ind[num2 + 1] && i1 <= ind[num2 + 1]) ans--;

    ind[num2] = i1;

    cout << ans << endl;
  }
}