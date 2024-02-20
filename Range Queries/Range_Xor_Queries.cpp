// Problem -> https://cses.fi/problemset/task/1650

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> pf{ 0 };

  for (int i = 0, x; i < n; i++) {
    cin >> x;

    pf.push_back(pf.back() ^ x);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    cout << (pf[r] ^ pf[l - 1]) << endl;
  }
}