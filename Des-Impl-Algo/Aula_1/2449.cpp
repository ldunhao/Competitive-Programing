#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, m, v,tmp=0, cont=0;

    vector<int> chaves;


    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;

    for(int i=0;i<n;i++) {cin >> v; chaves.push_back(v);}

    for(int i=0;i<n-1;i++){
        tmp = m - chaves[i];

        chaves[i] += tmp;
        chaves[i+1] +=tmp;

        cont += abs(tmp);
        tmp = 0;

    }

    cout << cont << endl;

}