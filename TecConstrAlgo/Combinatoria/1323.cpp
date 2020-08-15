#include <bits/stdc++.h>
using namespace std;

#define mod 1000007;

typedef long long int lli;

lli T(int n){
  lli aux;
  if(n == 1) return 1;
  else{
    return T(n-1) + (n * n);
  }
}

int main() {
  int n;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  while(cin >> n){
    if(n == 0) break;

    cout << T(n) << endl;
  }

  return 0;
}