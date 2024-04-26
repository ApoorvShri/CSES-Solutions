// https://cses.fi/problemset/task/1081

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int maxN = 1e6 + 1;
  vector<int> cnt(maxN);

  for (int i = 0, x; i < n; i++) {
    cin >> x;
    cnt[x]++;
  }

  int mx = 1;

  for (int i = 1; i < maxN; i++) {
    for (int j = 2 * i; j < maxN; j += i) cnt[i] += cnt[j];
    if (cnt[i] > 1) mx = i;
  }

  cout << mx << endl;
}