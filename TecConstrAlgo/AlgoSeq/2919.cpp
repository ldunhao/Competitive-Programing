#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end();

const long long int MOD = 1e9-1;
const long long int MAXN = 1e6;

typedef long long int lli;
typedef vector<vector<lli>> matrix;


lli find_lis(vector<lli> v){
    int n = v.size(), len=0;
    vector<int> tam(n), dad(n);

    for(int i = 0; i < n; i++){
        int lo=0, hi=len;
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(v[tam[mid]]<v[i]) lo = mid+1;
            else hi=mid;
        }
        dad[i] = (lo>0) ? tam[lo-1] : -1;
        tam[lo] = i;
        if(lo == len) len++;
    }

    vector<lli> ans(len);

    for (int u = tam[len-1], i = len-1; u != -1; u = dad[u], i--)
        ans[i] = v[u];
    
    return ans.size();
}

int main(){
    lli num;
    int n;

    vector<lli> arr;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while(cin >> n){
        for(int i=0;i<n;i++) cin >> num, arr.push_back(num);

        cout << find_lis(arr) << endl;

        arr.clear();
    }
    

    return 0;
}