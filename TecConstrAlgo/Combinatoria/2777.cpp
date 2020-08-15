#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;

const long long int mod = 1e9+7;
long long mat_size = 3;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

matrix mult(matrix a, matrix b){
    matrix c(mat_size, vector<lli>(mat_size));
    for(int i = 0; i < mat_size; i++)
        for(int j = 0; j < mat_size; j++)
            for(int k = 0; k < mat_size; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    return c; 
}

matrix pow(matrix base, lli n){
    if(n == 1) return base;
    if(n & 1) return mult(base, pow(base, n - 1));
    matrix tmp = pow(base, n/2);
    return mult(tmp, tmp);
}

int main() {
  lli n, ans;
  matrix aux;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  matrix base = {{ 0, 1, 1 }, { 1, 0 ,0 }, { 0 ,1 ,0 }};

  while(cin >> n){
    if(n==1) ans=1;
    else if(n==2) ans = 2;
    else if(n==3) ans = 2;
    else{
      aux = pow(base, n-3);
      ans = (aux[0][0] * 2)%mod + (aux[0][1] * 2)%mod + (aux[0][2] * 1)%mod;
    }
    cout << ans%mod << endl;
  }

  return 0;
}