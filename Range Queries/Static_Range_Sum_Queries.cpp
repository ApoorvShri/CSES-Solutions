// Problem -> https://cses.fi/problemset/task/1646

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<long long> pf{ 0 };

  for (int i = 0;i < n;i++) {
    int x;
    cin >> x;

    pf.push_back(x + pf.back());
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    cout << pf[r] - pf[l - 1] << endl;
  }
}