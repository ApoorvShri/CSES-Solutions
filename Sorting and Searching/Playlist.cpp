// Problem -> https://cses.fi/problemset/task/1141

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

/*
  int ans = 0, i = 0, j = 0, dist = 0;
  map<int, int> cnt;

  while (j < n) {
    cnt[a[j]]++;
    if (cnt[a[j]] == 1) dist++;

    while (dist < j - i + 1) {
      cnt[a[i]]--;
      if (cnt[a[i]] == 0) dist--;
      i++;
    }

    ans = max(ans, j - i + 1);
    j++;
  }
*/

/*
  int ans = 0, i = 0, j = 0;
  set<int> st;

  while (j < n) {
    while (st.count(a[j])) st.erase(a[i++]);
    st.insert(a[j]);

    ans = max(ans, int(st.size()));
    j++;
  }
*/

  int ans = 0;
  map<int, int> ind;

  for (int i = 0, j = 0;j < n;j++) {
    i = max(i, ind[a[j]]);
    ans = max(ans, j - i + 1);
    ind[a[j]] = j + 1;
  }

  cout << ans << endl;
}