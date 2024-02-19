// Problem -> https://cses.fi/problemset/task/1661

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  long long sum = 0, ans = 0;
  map<long long, long long> cnt;
  cnt[0] = 1;

  for (auto &it : a) {
    sum += it;
    ans += cnt[sum - x];
    cnt[sum]++;
  }

  cout << ans << endl;
}