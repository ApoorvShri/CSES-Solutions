// Problem -> https://cses.fi/problemset/task/1073

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  multiset<int> towerTop;

  for (int i = 0;i < n;i++) {
    auto it = towerTop.upper_bound(a[i]);

    if (it != towerTop.end()) towerTop.erase(it);
    towerTop.insert(a[i]);
  }

  cout << towerTop.size() << endl;
}