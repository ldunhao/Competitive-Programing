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

int T[MAXN+7][MAXN+7];


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;cin >> t;
  

  while(t--){
    int n;cin >> n;

    double b = n/2.0;

    double h = b/tan(36.0*pi/180.0);
    double At = 0.5*b*h;

    cout << setprecision(3) << fixed << At*10 << endl;
  }

  return 0;
}