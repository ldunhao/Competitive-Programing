#include <bits/stdc++.h>

using namespace std;
 
#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;
#define all(v) (v).begin(), (v).end()
 
#define endl '\n'
#define MAX 100000
#define MOD 1000000009
#define INF INT32_MAX
#define INFLL INT64_MAX
 
typedef long long int lli;
typedef long double ld;
 
vector<lli> fact = {1, 1};
 
pair<lli, lli> egcd(lli a, lli b) {
  lli x = 0, lastx = 1, auxx;
  lli y = 1, lasty = 0, auxy;
  while (b) {
    lli q = a / b, r = a % b;
    a = b, b = r;
    auxx = x;
    x = lastx - q * x, lastx = auxx;
    auxy = y;
    y = lasty - q * y, lasty = auxy;
  }
  return {lastx, lasty};
}
 
int main(void){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  for(lli i = 2; i <= 100000; i++) fact.push_back((i*fact.back())%MOD);
 
  lli t, n, tmp = egcd(6, MOD).first;
  tmp = (tmp % MOD + MOD) % MOD;
  while(cin >> n) {
    if(!n) break;
    cout << (fact[n] * tmp) % MOD << endl;
  }
 
  return 0;
}
 