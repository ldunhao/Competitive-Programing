#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;
using namespace std;

const long long MOD = 100000007;
 
long long fat[10010];
 
int gcde(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcde(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}
 
void solve() {
	fat[0] = 1;
	fat[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		fat[i] = (i % MOD * fat[i - 1] % MOD) % MOD;
	}
}
 
long long inv(int a, long long m) {
	int x, y;
	int g = gcde(a, m, x, y);
	if (g != 1) {
		return -1;
	} else {
		if (x % m < 0) x += m;
		x = (x % m + m) % m;
		return x;
	}
}
 
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

	solve();
 
  while (cin >> s) {
    if (s == "0") {
      break;
    }

    int n = (int)s.size();
    vector<int> freq(26);

    for (int i = 0; i < n; i++) {
      freq[s[i] - 'a']++;
    }

    long long tmp = fat[n] % MOD;
    long long tmp2 = 1;

    for (int i = 0; i < 26; i++) {
      tmp2 = (tmp2 % MOD * fat[freq[i]] % MOD) % MOD;
    }

    cout << (tmp % MOD * inv(tmp2, MOD) % MOD) % MOD << endl;
  }

  return 0;
}