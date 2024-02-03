#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> pf;

  for (int i = 0;i < n;i++) {
    int st, en;
    cin >> st >> en;

    pf[st]++;
    pf[en]--;
  }

  int cnt = 0, ans = 0;
  for (auto &it : pf) {
    cnt += it.second;
    ans = max(ans, cnt);
  }

  cout << ans << endl;
}