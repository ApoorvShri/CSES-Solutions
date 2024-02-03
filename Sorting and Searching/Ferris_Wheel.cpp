#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  sort(a.begin(), a.end());

  int i = 0, j = n - 1, ans = 0;
  while (i <= j) {
    ans++;

    if (i != j && a[i] + a[j] <= x) i++, j--;
    else j--;
  }

  cout << ans << endl;
}