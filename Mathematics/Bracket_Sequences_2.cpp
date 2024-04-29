// Problem -> https://cses.fi/problemset/task/2187

/*
Lets consider a 2d plane where in i,j
i represents the total number of moves made and
j represents the difference between the total number of opening and closing brackets

number of ways to move from A(x1,y1) to B(x2,y2) = (x+y)C(x), where
x + y = x2 - x1
x - y = y2 - y1
from these 2 equations we can find x

to find the number of ways to move from A(x1,y1) to B(x2,y2) without crossing or touching a line
mirror A(x1,y2) along this line which will give C(x3,y3)
w1 = number of ways to move from A to B
w2 = number of ways to move from C to B
number of ways to move from A to B without crossing a line = w1 - w2

here n = length of sequence
x1 = number of opening + closing brackets in the prefix
y1 = number of opening - closing brackets in the prefix
we have to move from A(c1,c2) to B(n,0) and we cannot move below y=0 or touch y=-1 because it will form an unbalanced sequence
mirror A(x1,y1) along y=-1 which will give C(x1,-1-(y2-(-1))) = C(x1,-y1-2)

for w1, A(x1,y1) to B(n,0)
x + y = n - x1
x - y = -y1
x = (n - x1 - y1) / 2
w1 = (n - x1)C(x)

for w2, C(x1,-y1-2) to B(n,0)
x + y = n - x1
x - y = y1 + 2
x = (n + y1 - x1) / 2 + 1
w2 = (n - x1)C(x)

number of ways = w1 - w2

let k denote the excess opening brackets which we need to close and n denote the remaining pairs
number of ways = Cn(k) = (k+1)/(n+k+1) * (2n+k)C(n)
this is basically a convolution on Catalan

if the sequence is not a prefix, like for a sequence ( _ _ _ _ )
we have to calculate the number of ways to move from A(1,1) to B(5,1) without crossing the line y=0 or touching y=-1
*/

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7, maxN = 1e6;
vector<int> fact(maxN, 1);

int inverse(int x) {
  return x <= 1 ? x : mod - 1ll * mod / x * inverse(mod % x) % mod;
}

int nCr(int n, int r) {
  return 1ll * fact[n] * inverse(fact[r]) % mod * inverse(fact[n - r]) % mod;
}

int main() {
  for (int i = 2; i < maxN; i++)  fact[i] = 1ll * fact[i - 1] * i % mod;

  int n;
  string s;
  cin >> n >> s;

  if (n & 1) {
    cout << 0 << endl;
    return 0;
  }

  n /= 2;
  int open = 0, close = 0;

  for (char &it : s) {
    if (it == '(') open++;
    else close++;

    if (close > open || open > n) {
      cout << 0 << endl;
      return 0;
    }
  }

  n -= open;
  int k = open - close;

  cout << 1ll * (k + 1) * inverse(n + k + 1) % mod * nCr(2 * n + k, n) % mod << endl;
}