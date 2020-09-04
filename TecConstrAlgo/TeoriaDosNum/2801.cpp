#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;
#define all(x) (x).begin(),(x).end()

const long long int mod = 1e9-1;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

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

int main(){
  int n;
  lli t,a,b,aux;
  vector<int> msg;
  vector<int> ans;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  cin >> n;
  int m;
  while(n--){
    cin >> m;
    msg.push_back(m);
  }
  cin >> t >> a >> b;

  if(__gcd(a,t) == 1){
    for(int i=0;i<msg.size();i++){
      aux = inv(a,t)*(msg[i]-b)%t;
      ans.push_back(aux);
    }
    for(int i=0;i<msg.size()-1;i++){
      cout << (ans[i]+t)%t << " ";
    }
    cout << (ans[msg.size()-1]+t)%t << endl;
  }
  else cout << "DECIFRAGEM AMBIGUA" << endl;

  return 0;
}