#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;

const long long int mod = 1e9+7;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

lli phi(lli n) {
    lli result = n;
    for (lli i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result/2;
}

int main() {
  lli n,rq,cont=0;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  while(cin >> n){

    if(n==3) cont=1;
    else if(n==4) cont=1;
    else{
      cont = phi(n);
    }

    cout << cont << endl;
  }

  return 0;
}