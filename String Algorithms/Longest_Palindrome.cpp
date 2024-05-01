// Problem -> https://cses.fi/problemset/task/1111

#include<bits/stdc++.h>
using namespace std;

class Manacher {
public:
  vector<int> p;

  void build(string &s) {
    int n = s.size();
    p.assign(n, 1);

    for (int i = 1, l = 1, r = 1; i < n; i++) {
      p[i] = max(1, min(r - i, p[l + r - i]));

      while (i - p[i] >= 0 && i + p[i] < n && s[i - p[i]] == s[i + p[i]]) p[i]++;

      if (i + p[i] > r) {
        l = i - p[i];
        r = i + p[i];
      }
    }
  }

  Manacher(string &s) {
    string t = "#";
    for (char &ch : s) t += ch, t += '#';

    build(t);
  }

// gives length of the longest palindrome with center at cen either odd or even
  int longestPal(int cen, bool odd) {
    int pos = 2 * cen + 1 + (!odd);
    return p[pos] - 1;
  }

// checks whether the string is palindrome form l to r
  bool isPal(int l, int r) {
    return longestPal((l + r) / 2, l % 2 == r % 2) >= r - l + 1;
  }
};

int main() {
  string s;
  cin >> s;

  Manacher m(s);
  int start = 0, end = 0;

  for (int i = 0, len; i < s.size(); i++) {
    len = max(m.longestPal(i, 0), m.longestPal(i, 1));
    if (len > end - start + 1) {
      start = i - (len - 1) / 2;
      end = i + len / 2;
    }
  }

  string ans = "";
  for (int i = start; i <= end; i++) ans += s[i];

  cout << ans << endl;
}