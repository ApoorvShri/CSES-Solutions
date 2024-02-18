// Problem -> https://cses.fi/problemset/task/1660

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  int ans = 0, i = 0, j = 0;

  while (j < n) {
    x -= a[j];
    while (x < 0) x += a[i++];

    ans += x == 0;
    j++;
  }

  cout << ans << endl;
}