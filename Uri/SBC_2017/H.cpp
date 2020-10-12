#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end()

const int INF = 0x3f3f3f3f;
const long long int MOD = 1e9-1;
const long long int MAXN = 5e3;
const long double PI = acos(-1.0);
const double QZERO = 0.000000001;
const double EPS = 1e-9;

typedef long long int lli;
typedef vector<vector<char>> matrix;

int find_lis(vector<pair<double,double>> v){
    int n = v.size(), len=0;
    vector<int> tam(n), dad(n);

    for(int i = 0; i < n; i++){
        int lo=0, hi=len;
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(v[tam[mid]].second<v[i].second) lo = mid+1;
            else hi=mid;
        }
        dad[i] = (lo>0) ? tam[lo-1] : -1;
        tam[lo] = i;
        if(lo == len) len++;
    }

    vector<pair<double,double>> ans(len);

    for (int u = tam[len-1], i = len-1; u != -1; u = dad[u], i--)
        ans[i] = v[u];
    
    return ans.size();
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

    int n,a,b;
    cin >> n >> a >>b;

    vector<pair<int,int>> pontos;
    vector<pair<double,double>> angs;

    double base = b-a;

    while(n--){
        int x,y;cin >> x >> y;
        pontos.push_back(make_pair(x,y));

        double angA = atan2(y,abs(x-a)),angB = atan2(y,abs(x-b));

        angs.push_back(make_pair(angA,angB));
    }

    sort(all(angs));

    cout << find_lis(angs) << endl;
    
    return 0;
}