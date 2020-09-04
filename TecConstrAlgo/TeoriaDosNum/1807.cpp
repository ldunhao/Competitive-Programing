#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;
#define all(x) (x).begin(),(x).end()

const long long int mod = (long long)((1LL << 31) - 1LL);

typedef long long int lli;
typedef vector<vector<lli>> matrix;

long long fast_exp(long long a, long long b){
    long long result = 1;
    while(b){
        if(b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

int main(){
  lli e;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  cin >> e;
  cout << fast_exp(3,e) << endl;

  return 0;
}