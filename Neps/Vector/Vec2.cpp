#include <bits/stdc++.h>
using namespace std;

int main(void){
    int p,m,n;
    int k;
    char s;
    vector<int> cartas;
    vector<char> naipes;

    cin >> p >> m >> n;

    while(p!=0 && m!=0 && n!=0){
        for (int i=0; i<n; i++){
            cin >> k >> s;
            cartas.push_back(k);
            naipes.push_back(s);
        }
    }
}