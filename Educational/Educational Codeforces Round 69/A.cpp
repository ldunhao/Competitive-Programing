#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long int queries, qtd, n, sMaior=0, maior=0;
    vector<int> num;
    cin>>queries;
    for(int i=1;i<=queries; i++){
        cin>>qtd;
        for(int j=1;j<=qtd; j++){
            cin>>n;

            num.push_back(n);
            if(n>=maior){
                sMaior=maior;
                maior=n;
            }
        }
        sort(num.begin(),num.end(),greater<int>());
        // maior=num[0];
        // sMaior=num[0];   
        // while(sMaior==maior){
        //     sMaior=num[i];
        //     i++;
        // }
        sMaior = num[1]-1;
        int tam = num.size()-2;
        int cont=0;
        while(sMaior != 0 && tam != 0 ){
            cont ++;
            tam --;
            sMaior --;
            
        }
        cout << cont << endl;
        num.clear();
    }
    return 0;
}
