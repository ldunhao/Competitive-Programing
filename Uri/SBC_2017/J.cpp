#include <bits/stdc++.h>
 
using namespace std;
 
#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;
 
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);
 
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
 
    cin >> s;
 
    long long sum = 0;
 
    for (int i = 0; i < (int)s.size(); i++) {
        sum += s[i] - '0';
    }
 
    cout << sum % 3 << endl;
 
    return 0;
}