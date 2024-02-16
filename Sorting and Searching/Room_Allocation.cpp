// Problem -> https://cses.fi/problemset/task/1164

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(3));
  for (int i = 0;i < n;i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i;
  }

  sort(a.begin(), a.end());
  set<pair<int, int>> st;
  vector<int> ans(n);
  int cur = 0;

  for (auto &it : a) {
    auto sm = st.lower_bound({ it[0],0 });

    if (sm == st.begin()) {
      ans[it[2]] = ++cur;
      st.insert({ it[1],cur });
    }
    else {
      sm--;
      ans[it[2]] = sm->second;

      st.erase(sm);
      st.insert({ it[1],ans[it[2]] });
    }
  }

  cout << cur << endl;
  for (auto &it : ans) cout << it << " ";
  cout << endl;
}