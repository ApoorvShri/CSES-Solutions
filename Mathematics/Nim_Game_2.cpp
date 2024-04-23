// Problem -> https://cses.fi/problemset/task/1098

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
      ans ^= x % 4;
    }

    if (ans) cout << "first" << endl;
    else cout << "second" << endl;
  }
}