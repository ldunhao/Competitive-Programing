#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    int a,cont = 0;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> q;
        for (int j=0;j<q;j++){
            cin >> a;
            cont += a;
        }
        cont = (cont-1)/q + 1;
        cout << cont << endl;
        cont = 0;
    }

    return 0;
}