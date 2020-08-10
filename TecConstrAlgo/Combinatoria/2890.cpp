#include <bits/stdc++.h>
#define MOD 1000007;

using namespace std;

int main(){
  long long int n,a,b,aux,resp;

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  cin >> n;
  while(n!=0){
    a = n*n*n*n;
    b = 11*(n*n);
    aux = a+b;
    resp = (aux/12)%MOD;
    cout << resp << endl;
    a=0;b=0;resp=0;
    cin >> n;
  }

  return 0;
}