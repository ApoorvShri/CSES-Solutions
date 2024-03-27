// Problem - https://cses.fi/problemset/task/1749

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
    int cnt;
  };

  vector<Node> seg;

  SegTree(int n) {
    seg.resize(4 * n);
  }

  Node merge(Node left, Node right) {
    return { left.cnt + right.cnt };
  }

  void build(int ind, int low, int high) {
    if (low == high) {
      seg[ind] = { 1 };
      return;
    }

    build(leftChild);
    build(rightChild);

    seg[ind] = merge(seg[leftInd], seg[rightInd]);
  }

  void update(int ind, int low, int high, int pos) {
    if (low == high) {
      seg[ind] = { 0 };
      return;
    }

    if (pos <= mid) update(leftChild, pos);
    else update(rightChild, pos);

    seg[ind] = merge(seg[leftInd], seg[rightInd]);
  }

  int query(int ind, int low, int high, int pos) {
    if (low == high) return low;

    if (seg[leftInd].cnt >= pos) return query(leftChild, pos);
    return query(rightChild, pos - seg[leftInd].cnt);
  }
};

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  SegTree st(n);
  st.build(0, 0, n - 1);

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;

    int res = st.query(0, 0, n - 1, val);
    cout << a[res] << " ";
    
    st.update(0, 0, n - 1, res);
  }

  cout << endl;
}