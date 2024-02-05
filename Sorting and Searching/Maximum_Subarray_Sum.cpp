#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  long long ans = INT_MIN, sum = 0;
  for (auto &it : a) {
    sum += it;
    ans = max(ans, sum);
    sum = max(sum, 0ll);
  }

  cout << ans << endl;
}