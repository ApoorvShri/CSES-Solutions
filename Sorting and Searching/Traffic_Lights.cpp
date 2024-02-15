// Problem -> https://cses.fi/problemset/task/1163

#include<bits/stdc++.h>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;

  vector<int> a(n), ans(n);
  for (auto &it : a) cin >> it;

  int res = 0;
  set<int> pos{ a.begin(),a.end() };

  pos.insert(0);
  pos.insert(x);

  for (auto cur = pos.begin();cur != pos.end();cur++) {
    if (cur == pos.begin() || cur == --pos.end()) continue;
    auto prev = cur, next = cur;
    prev--;
    next++;
    res = max({ res,*cur - *prev,*next - *cur });
  }

  for (int i = n - 1;i >= 0;i--) {
    ans[i] = res;
    auto cur = pos.find(a[i]), prev = cur, next = cur;
    prev--;
    next++;
    pos.erase(cur);
    res = max(res, *next - *prev);
  }

  for (auto &it : ans) cout << it << " ";
  cout << endl;
}