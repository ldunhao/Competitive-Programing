#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;
#define mod 100000;

typedef long long int lli;

double mat[5010][5010];

int main(){
  int n;
  
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  cin >> n;

  mat[1][1] = 1.0;
  for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
          if (j <= i) {
              mat[i][j] = (mat[i - 1][j] * 0.5) + (mat[i - 1][j - 1] * 0.5);
          }
      }
  }

  cout << fixed << setprecision(2) << mat[n][(n + 1) / 2] * 100 << endl;

  return 0;
} 
