// Problem -> https://cses.fi/problemset/task/2064

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

here n = number of opening or closing brackets
we have to move from A(0,0) to B(2n,0) and we cannot move below y=0 or touch y=-1 because it will form an unbalanced sequence
mirror A(0,0) along y=-1 which will give C(x1,-1-(y2-(-1))) = C(x1,-y1-2) = C(0,-2)

for w1, A(0,0) to B(2n,0)
x + y = 2n
x - y = 0
x = n
w1 = (2n)C(n)

for w2, C(0,-2) to B(2n,0)
x + y = 2n
x - y = 2
x = n + 1
w2 = (2n)C(n+1)

number of ways = w1 - w2 = (2n)C(n) - (2n)C(n+1) = 1/(n+1) * (2n)C(n)

number of valid bracket sequences of length n = Catalan number = 1/(n+1) * (2n)C(n)
*/

#include<bits/stdc++.h>
using namespace std;

int inverse(int x, int mod) {
  return x <= 1 ? x : mod - 1ll * mod / x * inverse(mod % x, mod) % mod;
}

int main() {
  int n;
  cin >> n;

  if (n & 1) {
    cout << 0 << endl;
    return 0;
  }

  n /= 2;
  int factN = 1, fact2N = 1, mod = 1e9 + 7;

  for (int i = 2; i <= 2 * n; i++) {
    if (i <= n) factN = 1ll * factN * i % mod;
    fact2N = 1ll * fact2N * i % mod;
  }

  cout << 1ll * inverse(n + 1, mod) * fact2N % mod * inverse(factN, mod) % mod * inverse(factN, mod) % mod << endl;
}