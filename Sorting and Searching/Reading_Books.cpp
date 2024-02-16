// Problem -> https://cses.fi/problemset/task/1631

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  long long sum = 0, mx = 0;

  for (int i = 0;i < n;i++) {
    int x;
    cin >> x;

    sum += x;
    mx = max(mx, 1ll * x);
  }

  cout << max(2 * mx, sum) << endl;
}