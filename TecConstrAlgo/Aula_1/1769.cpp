#include <bits/stdc++.h>

using namespace std;

int main (){
    int n , cont1=0, cont2=0, b1, b2;
    string cpf;

    vector<int> cpfNum;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    while(cin >> cpf){
        int contTmp = 0;

        for(int i=0;i<cpf.size();i++){
            if(isdigit(cpf[i])) {
                
                cpfNum.push_back(cpf[i] - 48);
                int tmp1 = cpf[i] - 48;
                contTmp++;
                if (i<11) {
                    cont1 += tmp1*contTmp;
                    cont2 += tmp1*(10-contTmp);
                }
                    
            }
        }

        if(cont1%11 == 10) b1=0;
        else b1 = cont1%11;

        if(cont2%11 == 10) b2=0;
        else b2 = cont2%11;
       
        int tmp = cpfNum.size();

        if(b1==cpfNum[tmp-2] && b2==cpfNum[tmp-1]) {
            cout << "CPF valido" << endl;
        }else cout << "CPF invalido" << endl;

        cont1 = 0;
        cont2 = 0;
        b1 = 0;
        b2 = 0;
    }
    
    
    return 0;
}