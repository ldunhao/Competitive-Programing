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

  int l,c,r1,r2;
  bool ans = true;

  while(cin >> l >> c >> r1 >> r2){
    if(l == 0) break;

    if(max(r1,r2)*2 > min(l,c)) ans = false;

    int cat1 = l-(r1+r2), cat2 = c-(r1+r2);
    int h = sqrt(pow(cat1,2) + pow(cat2,2));

    if(r1+r2 > h) ans = false;

    (ans) ? cout << 'S' << endl : cout << 'N' << endl;

    ans = true;
  }

  return 0;
}