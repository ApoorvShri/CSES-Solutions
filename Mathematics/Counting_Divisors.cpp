// Problem -> https://cses.fi/problemset/task/1713

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int maxNum = 1e6 + 1;
  vector<int> cnt(maxNum);

  for (int i = 1; i < maxNum; i++) {
    for (int j = i; j < maxNum; j += i) cnt[j]++;
  }

  while (n--) {
    int x;
    cin >> x;

    cout << cnt[x] << endl;
  }
}

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//   int n;
//   cin >> n;

//   while (n--) {
//     int x, ans = 0;
//     cin >> x;

//     for (int i = 1; i * i <= x; i++) {
//       if (x % i == 0) {
//         ans++;
//         if (x / i != i) ans++;
//       }
//     }

//     cout << ans << endl;
//   }
// }