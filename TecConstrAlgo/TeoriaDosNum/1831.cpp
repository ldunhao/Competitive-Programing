#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;
#define all(x) (x).begin(),(x).end()

const long long int mod = 1e9+7;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

int inv(int a, int m) { 
  int m0 = m, t, q; 
  int x0 = 0, x1 = 1; 

  if (m == 1) 
      return 0; 

  while (a > 1){ 
      q = a / m; 
      t = m; 
      m = a % m, a = t; 
      t = x0; 
      x0 = x1 - q * x0; 
      x1 = t; 
  } 

  if (x1 < 0) 
      x1 += m0; 

  return x1; 
} 

lli findMinX(vector<lli> a, vector<lli> b, int k) { 
  lli prod = 1; 
  for (int i = 0; i < k; i++){ 
    prod *= a[i]; 
  }

  lli result = 0; 

  for (int i = 0; i < k; i++){ 
    lli pp = prod / a[i]; 
    result += b[i] * inv(pp, a[i]) * pp; 
  } 

  return result % prod; 
}

int main(){
  int caso=1;
  vector<lli> r(3),n(3);

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  while(cin>>r[0]>>n[0]>>r[1]>>n[1]>>r[2]>>n[2]){
    if(r[0]==0 && r[1]==0 && r[2]==0){
      cout << "Caso #" << caso << ": " << n[0]*n[1]*n[2] << " laranja(s)" << endl;
    }else{
      cout << "Caso #" << caso << ": " << findMinX(n,r,3) << " laranja(s)" << endl;
    }
    caso++;
  }

  return 0;
}