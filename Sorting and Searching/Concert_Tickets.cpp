#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  multiset<int> st;

  for (int i = 0;i < n;i++) {
    int h;
    cin >> h;

    st.insert(h);
  }

  for (int i = 0;i < m;i++) {
    int t;
    cin >> t;

    auto it = st.upper_bound(t);

    if (it == st.begin()) cout << -1 << endl;
    else {
      cout << *(--it) << endl;
      st.erase(it);
    }
  }
}