#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;
#define all(x) (x).begin(),(x).end()

const long long int mod = 1e9+7;

typedef long long int lli;
typedef vector<vector<lli>> matrix;
 
int findDigitRootOfString(string s) {
  int digit_root = 0;

  for (int i = 0; i < (int)s.size(); i++) {
      digit_root = (digit_root + s[i] - '0') % 9;
  }

  return digit_root = (digit_root == 0 ? 9:digit_root);
}
 
int findDigitRootOfNumber(int num) {
  int digit_root = 0;

  while (num > 0) {
      digit_root = (digit_root + (num % 10)) % 9;
      num /= 10;
  }

  return digit_root = (digit_root == 0 ? 9:digit_root);
}
 
int main(void){
  string b, e;

  cin >> b >> e;

  int b_nf = findDigitRootOfString(b);
  int num = 1, expByNum = 1, nf = 1, nf2 = 1, nf3 = 1, expByTen = 1;

  for (int i = 0; i < (int)e.size(); i++) {
    num = (int)(e[i] - '0');
    expByNum = (int)(pow(b_nf, num) + 0.5);
    nf = findDigitRootOfNumber(expByNum);
    nf2 = findDigitRootOfNumber(nf * nf3);
    expByTen = pow(nf2, 10);
    nf3 = findDigitRootOfNumber(expByTen);
  }

  cout << nf2 << endl;

  return 0;
}