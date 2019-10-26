#include <bits/stdc++.h>

using namespace std;

int main(void){

    int n,k,cont,cont_ext,valor;
    int maxi,aux=0,tmp=0,cont_final=0;
    vector<int> horas;

    cin >> n;
    cont=0,maxi = -1,cont_ext=0;


    for(int i=0;i<n;i++) {
        cin >> k;
        horas.push_back(k);
    }

    if(horas[0]==1 && horas[n-1]==1) cont_ext = 2;

    if(horas[n-1]==1) cont = 1;

    while(horas[tmp]!=0) aux++, tmp++;

    for(int i=0;i<n;i++){

        if(horas[i]==1) cont++;
        else {cont=0;}
        
        if(cont > maxi) maxi = cont;
    }
    
    if(horas[n-1]==1) cont_final = cont + aux;


    cout << max(max(cont_final,maxi),cont_ext) << endl;
}