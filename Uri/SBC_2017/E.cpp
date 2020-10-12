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
 
    unordered_map<int, string> mp;
 
    mp[0] = "do";
    mp[1] = "do#";
    mp[2] = "re";
    mp[3] = "re#";
    mp[4] = "mi";
    mp[5] = "fa";
    mp[6] = "fa#";
    mp[7] = "sol";
    mp[8] = "sol#";
    mp[9] = "la";
    mp[10] = "la#";
    mp[11] = "si";
 
    int n;
 
    cin >> n;
 
    vector<int> s;
 
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        x--;
        s.push_back(x % 12);
    }
 
    for (int i = 0; i < 12; i++) {
        int cnt = 0;
 
        for (auto x : s) {
            if (x == i) {
                cnt++;
            } else if (x == (i + 2) % 12) {
                cnt++;
            } else if (x == (i + 4) % 12) {
                cnt++;
            } else if (x == (i + 5) % 12) {
                cnt++;
            } else if (x == (i + 7) % 12) {
                cnt++;
            } else if (x == (i + 9) % 12) {
                cnt++;
            } else if (x == (i + 11) % 12) {
                cnt++;
            }
        }
 
        if (cnt == n) {
            cout << mp[i] << endl;
            return 0;
        }
    }
 
    cout << "desafinado" << endl;
 
    return 0;
}