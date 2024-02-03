#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;

  vector<int> a(n);
  for(auto &it:a) cin>>it;

  sort(a.begin(),a.end());

  int ans=1;
  for(int i=1;i<n;i++){
    if(a[i]!=a[i-1]) ans++;
  }

  cout<<ans<<endl;
}