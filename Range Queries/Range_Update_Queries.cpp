// Problem -> https://cses.fi/problemset/task/1651

#include<bits/stdc++.h>
using namespace std;

class SegTree {
public:
  vector<long long> seg;

  SegTree(int n) {
    seg.resize(4 * n);
  }

  void update(int ind, int low, int high, int pos, int val) {
    if (low == high) {
      seg[ind] += val;
      return;
    }

    int mid = low + (high - low) / 2;

    if (pos <= mid) update(2 * ind + 1, low, mid, pos, val);
    else update(2 * ind + 2, mid + 1, high, pos, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
  }

  long long query(int ind, int low, int high, int l, int r) {
    if (low > r || high < l) return 0;

    if (low >= l && high <= r) return seg[ind];

    int mid = low + (high - low) / 2;

    long long left = query(2 * ind + 1, low, mid, l, r);
    long long right = query(2 * ind + 2, mid + 1, high, l, r);

    return left + right;
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  SegTree st(n + 1);

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;

      st.update(0, 0, n, l - 1, x);
      st.update(0, 0, n, r, -x);
    }

    else {
      int pos;
      cin >> pos;

      cout << a[pos - 1] + st.query(0, 0, n, 0, pos - 1) << endl;
    }
  }
}