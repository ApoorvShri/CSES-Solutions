// Problem -> https://cses.fi/problemset/task/1641

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> a(n);
  for (int i = 0;i < n;i++) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a.begin(), a.end());
  for (int i = 0;i < n - 2;i++) {
    int j = i + 1, k = n - 1, sum = x - a[i].first;

    while (j < k) {
      if (a[j].first + a[k].first == sum) {
        cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[k].second + 1 << endl;
        return 0;
      }

      else if (a[j].first + a[k].first < sum) j++;
      else k--;
    }
  }

  cout << "IMPOSSIBLE" << endl;
}