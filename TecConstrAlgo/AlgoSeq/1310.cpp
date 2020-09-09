#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end()

const long long int MOD = 1e9-1;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

lli sm=0,im=0,fm=0;
lli ss=0,is=0,fs=0;

void SCM(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        if(ss+arr[i] >= 0){
            ss += arr[i];
            fs = i;
            if(is = 0) is = i;
            else if(ss > sm){
                sm = ss;
                im = is;
                fm = fs;
            }
        }
        else{
            ss = 0;
            is = 0;
            fs = 0;
        }
    }
}

int main(){
    int n,cost;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while(cin >> n){
        cin >> cost;

        vector<int> val(n);

        int v;
        for(int i=0;i<n;i++) cin >> v, val[i] = v-cost;
        
        SCM(val);

        cout << sm << endl;

        sm=0,im=0,fm=0;
        ss=0,is=0,fs=0;
        val.clear();
    }
    

    return 0;
}