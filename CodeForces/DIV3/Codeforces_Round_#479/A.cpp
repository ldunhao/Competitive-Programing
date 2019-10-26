#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,k,res;

    cin >> n >> k;

    for(int i=0; i<k; i++){
        (n%10 != 0) ? n=n-1 : n=n/10;
    }
    cout << n;
    return 0;
}