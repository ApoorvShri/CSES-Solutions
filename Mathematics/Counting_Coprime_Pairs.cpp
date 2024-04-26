// Problem -> https://cses.fi/problemset/task/2417

/*
count of picking k(like pair, triplets etc.) numbers such that their gcd is x(1 is co-prime)
k is fixed but x can vary

1. find the count of numbers
2. from 1 to maxN, add the count of all multiples of i
3. form 1 to maxN, find cnt[i]Ck, that is the number of ways to pick k numbers from cnt[i]
4. from maxN to 1, subtract the ways of each multiple of i from ways[i]
5. ways[x] is the answer for x
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int maxN = 1e6 + 1;
  vector<long long> cnt(maxN);

  for (int i = 0, x; i < n; i++) {
    cin >> x;
    cnt[x]++;
  }

  for (int i = 1; i < maxN; i++) {
    for (int j = 2 * i; j < maxN; j += i) cnt[i] += cnt[j];
    cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
  }

  for (int i = maxN - 1; i > 0; i--) for (int j = 2 * i; j < maxN; j += i) cnt[i] -= cnt[j];

  cout << cnt[1] << endl;
}