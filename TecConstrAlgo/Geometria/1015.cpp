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

  pair<double,double> p1,p2;

  cin >> p1.first >> p1.second >> p2.first >> p2.second;

  double ans = (sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second)));

  cout << setprecision(4) << fixed << ans << endl;

  return 0;
}