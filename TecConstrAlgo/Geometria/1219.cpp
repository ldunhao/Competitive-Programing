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

  int a,b,c;

  while(cin >> a >> b >> c){
    double r,v,g,s;

    s = (a+b+c)/2.0;
    v = sqrt(s*(s-a)*(s-b)*(s-c));

    r = M_PI*(pow((v/s),2));
    g = M_PI*pow((a*b*c)/(4*v),2);

    cout << setprecision(4) << fixed << g-v << ' ' << v-r << ' ' << r << endl;
  }

  return 0;
}