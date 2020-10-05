#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end();

const int INF = 0x3f3f3f3f;
const long long int MOD = 1e9-1;
const long long int MAXN = 5e3;
const long double PI = acos(-1.0);
const double QZERO = 0.000000001;
const double EPS = 1e-9;

typedef long long int lli;
typedef vector<vector<char>> matrix;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;cin >> n;

  int mar[107][107];
  memset(mar,0,sizeof(mar));

  int ans=0,maxX=-1,maxY=-1;

  while(n--){
    int xi,yi,xf,yf;
    cin >> xi >> xf >> yi >> yf;
    
    maxX = max(maxX,xf);
    maxY = max(maxY,yf);

    for(int i=xi;i<xf;i++){
      for(int j=yi;j<yf;j++){
        if(mar[i][j] == 0) mar[i][j] = 1;
      }
    }
  }

  for(int i=0;i<maxX+1;i++){
    for(int j=0;j<maxY+1;j++){
      if(mar[i][j] == 1) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}