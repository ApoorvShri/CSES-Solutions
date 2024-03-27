// Problem - https://cses.fi/problemset/task/1143

#include<bits/stdc++.h>
using namespace std;

#define mid ( low + (high - low) / 2)
#define leftInd (2 * ind + 1)
#define rightInd (2 * ind + 2)
#define leftChild leftInd, low, mid
#define rightChild rightInd, mid + 1, high

class SegTree {
public:
  struct Node {
    int max;
  };

  vector<Node> seg;
  Node EMPTY;

  SegTree(int n) {
    seg.resize(4 * n);
    EMPTY = { 0 };
  }

  Node leaf(int val) {
    return { val };
  }

  Node merge(Node left, Node right) {
    return { max(left.max,right.max) };
  }

  void build(int ind, int low, int high, vector<int> &a) {
    if (low == high) {
      seg[ind] = leaf(a[low]);
      return;
    }

    build(leftChild, a);
    build(rightChild, a);

    seg[ind] = merge(seg[leftInd], seg[rightInd]);
  }

  void update(int ind, int low, int high, int pos, int val) {
    if (low == high) {
      seg[ind] = leaf(val);
      return;
    }

    if (pos <= mid) update(leftChild, pos, val);
    else update(rightChild, pos, val);

    seg[ind] = merge(seg[leftInd], seg[rightInd]);
  }

  int query(int ind, int low, int high, int val) {
    if (low == high) return low;

    if (seg[leftInd].max >= val) return query(leftChild, val);
    return query(rightChild, val);
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  SegTree st(n);
  st.build(0, 0, n - 1, a);

  while (q--) {
    int val;
    cin >> val;

    if (val > st.seg[0].max) cout << 0 << " ";
    else {
      int res = st.query(0, 0, n - 1, val);
      cout << res + 1 << " ";

      a[res] -= val;
      st.update(0, 0, n - 1, res, a[res]);
    }
  }

  cout << endl;
}