#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;

const long long int mod = 1e9+7;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

lli D[1000001],nd;

int main() {
  lli t,a,b,aux,aux2;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  while(cin >> t >> a >> b){
    if((t==0 && a==0 && b ==0)) break;

    aux = a*b/__gcd(a,b);

    nd=0;

    for(int i=1;i<t;i++){
      if(t%i==0) D[nd++] = i;
    }

    
    for(int i=0;i<nd;i++){
      aux2 = D[i]*aux/__gcd(D[i],aux);
      if(aux2 == t) cout << D[i] << " ";
    }
    cout << t << endl;
  }


  return 0;
}