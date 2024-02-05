#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> a(n);
  for (int i = 0;i < n;i++) cin >> a[i].first, a[i].second = i + 1;
  sort(a.begin(), a.end());

  int i = 0, j = n - 1;
  bool flag = 1;

  while (i < j) {
    int sum = a[i].first + a[j].first;

    if (sum == x) {
      cout << a[i].second << " " << a[j].second << endl;
      flag = 0;
      break;
    }

    else if (sum > x) j--;
    else i++;
  }

  if (flag) cout << "IMPOSSIBLE" << endl;
}