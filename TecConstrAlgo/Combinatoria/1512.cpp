#include <bits/stdc++.h>

using namespace std;

int MDC(int a, int b){
  if(b==0) return a;
  else return MDC(b, a%b);
}

int main(){
  long long int n,a,b;
  long long int resp = 0;

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  cin >> n >> a >> b;
  while(n != 0) {
    int aux = (a*b)/MDC(a,b);
    cout << ((n/a) + (n/b)) - ((n/aux)) << endl;
    cin >> n >> a >> b;
  }

  return 0;
}