// Problem -> https://cses.fi/problemset/task/2210

/*
burnside lemma is used for rotation and reflection questions
like given n nodes and m colors find the total number of distinct ways to color all nodes and rotating and reflecting that shape gives the same way
  1. find the axis of rotation and reflection
  2. for each rotation and reflection find the minimum number of nodes to color such that the whole shape is colored in that rotation or reflection without overlap
  3. ways = (sum of m^cnt[i]) / total number of rotations and reflections, because there are cnt[i] number of nodes which have m choices of colors and others are colored with the same color in that rotation or reflection

here m=2 and there is no reflection and rotation is done by 0, 90, 180 and 270 degree
270 is same as 90 as it is the 90 degree rotation anticlockwise

1. n is even
   0   -> n^2
   90  -> (n/2)*(n/2)
   180 -> n*(n/2)
   270 -> (n/2)*(n/2)
  ways = (2^(n^2) + 2^((n^2)/4) + 2^((n^2)/2) + 2^((n^2)/4)) / 4

2. n is odd
   0   -> n^2
   90  -> ((n-1)/2)*((n+1)/2) + 1
   180 -> (n-1)*((n+1)/2) + 1
   270 -> ((n-1)/2)*((n+1)/2) + 1
  ways = ( 2^(n^2) + 2 * ( 2^( ((n^2)-1) / 4) + 2^( ((n^2)-1) / 2) + 2^( ((n^2)-1) / 4) ) ) / 4
*/

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int binpow(int x, long long n) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    n >>= 1;
  }
  return res;
}

int inverse(int x) {
  return x <= 1 ? x : mod - 1ll * mod / x * inverse(mod % x) % mod;
}

int main() {
  long long n;
  cin >> n;

  if (n & 1) cout << (binpow(2, n * n) + 2ll * (2ll * binpow(2, (n * n - 1) / 4) % mod + binpow(2, (n * n - 1) / 2) % mod) % mod) % mod * inverse(4) % mod << endl;
  
  else cout << (binpow(2, n * n) + (2ll * binpow(2, n * n / 4) % mod) + binpow(2, n * n / 2) % mod) * inverse(4) % mod << endl;
}