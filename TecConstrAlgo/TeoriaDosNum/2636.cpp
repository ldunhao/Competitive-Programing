#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end()

long long int MOD;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

long long multMod(long long a, long long b, long long mod = MOD) {
  long long result = 0;

  while (b) {
    if (b & 1) {
        result = (result + a) % mod;
    }
    a = (a + a) % mod;
    b >>= 1;
  }

  return result;
}

long long addMod(long long x, long long c, long long mod = MOD) {
    return (x + c) % mod;
}

long long fast_exp(long long a, long long b ,long long n){
    long long result = 1;
    while(b){
        if(b & 1) result = (result * a) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return result;
}

bool isComposite(long long n, long long a, long long d, int s) {
  long long x = fast_exp(a, d, n);

  if (x == 1 || x == n - 1) {
    return false;
  }

  for (int r = 1; r < s; r++) {
    x = multMod(x, x, n);

    if (x == n - 1) {
      return false;
    }
  }

  return true;
};

bool millerRabin(long long n) {
  if (n < 2) {
    return false;
  }

  int r = 0;
  long long d = n - 1;

  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for (int a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
    if (n == a) {
      return true;
    }

    if (isComposite(n, a, d, r)) {
      return false;
    }
  }

  return true;
}

long long rho(long long n) {
  long long x, y, d, c = 1;

  if (n % 2 == 0) {
    return 2;
  }

  while (true) {
    x = y = 2;

    while (true) {
      x = addMod(multMod(x, x, n), c, n);
      y = addMod(multMod(y, y, n), c, n);
      y = addMod(multMod(y, y, n), c, n);
      d = __gcd(abs(x - y), n);

      if (d == n) {
        break;
      } else if (d > 1) {
        return d;
      }
    }
    
    c++;
  }

  return d;
}

void factorization(long long n, vector<long long> &factors) {
    if (n == 1 || millerRabin(n)) {
        return factors.push_back(n);
    }

    long long f = rho(n);
    factorization(f, factors);
    factorization(n / f, factors);
}


int main(){
  lli n;
  vector<long long> F;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  while(cin >> n){
    if(n==0) break;

    MOD = n;
    factorization(n,F);
    sort(all(F));

    cout << n << " = ";
    for(int i=0;i<F.size()-1;i++){
      cout << F[i] << " x ";
    }
    cout << F[F.size()-1] << endl;

    F.clear();
  }

  return 0;
}