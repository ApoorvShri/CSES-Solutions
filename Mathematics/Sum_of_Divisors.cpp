// Problem - https://cses.fi/problemset/task/1082
// Solution - https://usaco.guide/problems/cses-1082-sum-of-divisors/solution

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 1e9 + 7, inverseMod2 = 500000004;

ll sumFromLtoR(ll l, ll r) {
  return (((((r - l + 1) % mod) * ((l + r) % mod)) % mod) * inverseMod2) % mod;
}

int main() {
  ll n;
  cin >> n;

  ll sum = 0, divisor = 1;

  while (divisor <= n) {
    ll divisorContribution = n / divisor;
    ll lastDivisorWithSameContribution = n / divisorContribution;

    sum = (sum + divisorContribution * sumFromLtoR(divisor, lastDivisorWithSameContribution) % mod) % mod;
    divisor = lastDivisorWithSameContribution + 1;
  }

  cout << sum << endl;
}