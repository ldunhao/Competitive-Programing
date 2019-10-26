#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int n,m,aux,cont=0;

    cin >> n >> m;
    aux = m/n;
    while((aux%3)==0) aux/=3,cont++;
    while((aux%2)==0) aux/=2,cont++;
    if(n==m) cont = 0;
    else if (n>m || aux!=1 || m%n) cont = -1;
    cout << cont << endl;

}
