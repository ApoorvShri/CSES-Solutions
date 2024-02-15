// Problem -> https://cses.fi/problemset/task/2216

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  set<int> st;
  int ans = 1;

  for (auto &it : a) {
    if (st.count(it + 1)) ans++;
    st.insert(it);
  }

  cout << ans << endl;
}