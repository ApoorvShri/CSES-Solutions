// Problem -> https://cses.fi/problemset/task/1099

#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (i & 1) ans ^= x;
    }

    if (ans) cout << "first" << endl;
    else cout << "second" << endl;
  }
}