#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end();

const long long int MOD = 1e9-1;
const long long int MAXN = 5e3;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

int T[MAXN+7][MAXN+7];

int SCM(string s, string z,int n, int m){
    for(int i=0;i<n;i++) T[i][0] = 0;
    for(int i=0;i<m;i++) T[0][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == z[j-1]) T[i][j] = T[i-1][j-1]+1;
            else T[i][j] = max(T[i-1][j],T[i][j-1]);
        }
    }

    return T[s.size()][z.size()];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s,z;

    cin >> s >> z;

    int ans = s.size() + z.size() - SCM(s,z,s.size(),z.size());

    cout << ans << endl;

    return 0;
}