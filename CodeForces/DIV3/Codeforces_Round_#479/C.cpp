#include <bits/stdc++.h>
using namespace std;

int main(){

    long long int n,k,x=0,aux,soma=0;
    vector<long long int> num;

    cin >> n >> k;
    
    for(int i=0;i<n;i++) cin >> aux, num.push_back(aux);
    sort(num.begin() , num.end());

    if (k == 0){
        if(num[0] > 1) cout << 1;
        else cout << -1;
    }else if (k == n) {
        if(num[n-1]>= 1) cout << num[k-1];
        else cout << -1;
    }else if (num[k-1] == num[k]) cout << -1;
    else cout << num[k-1];

    return 0;
}