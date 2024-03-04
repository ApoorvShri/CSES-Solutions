// Problem - https://cses.fi/problemset/task/1645

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();

    if (st.empty()) cout << 0 << " ";
    else cout << st.top() + 1 << " ";

    st.push(i);
  }

  cout << endl;
}