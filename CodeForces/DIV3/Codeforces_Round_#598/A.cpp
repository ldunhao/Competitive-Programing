#include <bits/stdc++.h>

using namespace std;

int main(void){
    
    long long int q,a,b,n,s;

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    cin >> q;

    while(q--){
        cin >> a >> b >> n >> s;
        bool ok;
        ok = false;

        if(a*n+b>=s && s%n<=b)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;

}