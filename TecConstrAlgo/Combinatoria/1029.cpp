#include <bits/stdc++.h>

using namespace std;

int cont = 0;

int fib(int x){
  cont++;
  if(x == 0) return 0;
  else if(x == 1) return 1;
  else return (fib(x-1) + fib(x-2));
}

int main (){
  int n,x;

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> x;
    int aux = fib(x);
    cout << "fib(" << x << ") = " << cont - 1 << " calls = " << aux << endl;
    cont = 0;
  }

  return 0;
}