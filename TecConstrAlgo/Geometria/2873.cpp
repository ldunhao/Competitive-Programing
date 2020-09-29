#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end();

const long long int MOD = 1e9-1;
const long long int MAXN = 5e3;
const double pi = 2 * acos(0.0);

typedef long long int lli;
typedef vector<vector<char>> matrix;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  double a,b,c,d;

  while(cin >> a >> b >> c >> d){
    if(a == 0) break;

    double Hpo = sqrt(pow(c,2) + pow(d,2));
    double baseT = (a/2.0)+b;

    double aux = d/c;
    double x = baseT/aux;

    cout << setprecision(5) << fixed << x << endl;
  }

  return 0;
}