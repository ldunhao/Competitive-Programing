#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end()

const long long int MOD = 1e9-1;
const long long int MAXN = 1e6;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

vector<int> T(MAXN),O(MAXN);
int n;

int SCM(vector<lli> arr){
    int k=1,max=0,j;
    
    fill(T.begin(), T.end(), 0);
    fill(O.begin(), O.end(), 0);
    T[0] = arr[0];
    O[0] = 1;

    for(int i=1;i<n;i++){
        if(arr[i] > T[k]) k++, T[k]=arr[i], O[i]=k;
        else{
            j = lower_bound(all(T),arr[i]) - T.begin();
            T[j] = arr[i]; O[i] = j;
        }
    }

    max = *max_element(all(O));
    return max;

}

int main(){
    lli num;
    vector<int>::iterator low;
    vector<lli> arr;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while(cin >> n){
        for(int i=0;i<n;i++) cin >> num, arr.push_back(num);

        cout << SCM(arr) << endl;

        arr.clear();
    }
    

    return 0;
}