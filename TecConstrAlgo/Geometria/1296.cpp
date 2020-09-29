#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end();

const long long int MOD = 1e9-1;
const long long int MAXN = 5e3;

typedef long long int lli;
typedef vector<vector<char>> matrix;

int T[MAXN+7][MAXN+7];


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  double m1,m2,m3,ans;
  bool ok=false;

  while(cin >> m1 >> m2 >>m3){
    if(m1<(m2+m3) and m2<(m1+m3) and m3<(m1+m2)) ok=true;

    if(ok){
      double aux = (m1+m2+m3)/2.0;
      ans = 4.0/3.0*sqrt(aux*(aux-m1)*(aux-m2)*(aux-m3));

      cout << setprecision(3) << fixed << ans << endl;
    }else ans=-1, cout << setprecision(3) << fixed << ans << endl;

    ok = false;
  }

  return 0;
}