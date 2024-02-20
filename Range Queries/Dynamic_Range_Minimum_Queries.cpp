// Problem -> https://cses.fi/problemset/task/1649

#include<bits/stdc++.h>
using namespace std;

class SegTree {
public:
  vector<int> seg;

  SegTree(int n) {
    seg.resize(4 * n + 1);
  }

  int op(int x, int y) {
    return min(x, y);
  }

  void build(int ind, int low, int high, vector<int> &a) {
    if (low == high) {
      seg[ind] = a[low];
      return;
    }

    int mid = low + (high - low) / 2;

    build(2 * ind + 1, low, mid, a);
    build(2 * ind + 2, mid + 1, high, a);

    // According to operation
    seg[ind] = op(seg[2 * ind + 1], seg[2 * ind + 2]);
  }

  //* l and r should be passed 0 indexed
  int query(int ind, int low, int high, vector<int> &a, int l, int r) {
    // No overlap - (low high) (l r) or (l r) (low high)
    //! According to operation
    if (high<l || low>r) return INT_MAX;

    // Complete overlap - (l (low high) r)
    if (low >= l && high <= r) return seg[ind];

    // Partial overlap
    int mid = low + (high - low) / 2;

    int left = query(2 * ind + 1, low, mid, a, l, r);
    int right = query(2 * ind + 2, mid + 1, high, a, l, r);

    // According to operation
    return op(left, right);
  }

  //* ptr should be passed 0 indexed
  //* Also update the array while calling
  void pointUpdate(int ind, int low, int high, vector<int> &a, int ptr, int val) {
    if (low == high) {
      seg[ind] = val;
      return;
    }

    int mid = low + (high - low) / 2;

    if (ptr <= mid) pointUpdate(2 * ind + 1, low, mid, a, ptr, val);
    else pointUpdate(2 * ind + 2, mid + 1, high, a, ptr, val);

    // According to operation
    seg[ind] = op(seg[2 * ind + 1], seg[2 * ind + 2]);
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  SegTree segTree(n);
  segTree.build(0, 0, n - 1, a);

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int k, x;
      cin >> k >> x;

      segTree.pointUpdate(0, 0, n - 1, a, k - 1, x);
      a[k - 1] = x;
    }

    else {
      int l, r;
      cin >> l >> r;

      cout << segTree.query(0, 0, n - 1, a, l - 1, r - 1) << endl;
    }
  }
}