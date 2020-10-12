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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif


    int p;
    int n;cin >> n;
    int k;cin >> k;

    vector<int> pont;

    while(n--){
        cin >> p;
        pont.push_back(p);
    }

    sort(all(pont),greater<int>());

    int aux = pont[k-1];
    int cont=0;

    for(int i=k;i<pont.size();i++){
        if(pont[i]==aux){
            cont++;
        }
    }

    cout << k+cont << endl;
    return 0;
}